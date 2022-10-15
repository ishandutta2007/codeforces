#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>

using namespace std;

inline void raiseError(string errorCode) {
	cerr << "Error : " << errorCode << endl;
	exit(42);
}

class FastInput {
	private:
		static const int bufSize = 1 << 12;
		char buffer[bufSize+1];
		char *bufPtr;
		FILE *f;
		bool autoClose;
	public:
		inline char getChar() {
			if (*bufPtr == '\0') {
				int bytesRead = fread(buffer, 1, bufSize, f);
				buffer[bytesRead] = '\0';
				bufPtr = buffer;
			}
			if (*bufPtr == '\0') {
				return '\0';
			} else {
				return *(bufPtr++);
			}
		}
		
		inline string getToken() {
			char c = '\0';
			while (c <= ' ') {
				c = getChar();
			}
			string res = "";
			while (c > ' ') {
				res += c;
				c = getChar();
			}
			return res;
		}

		inline int getInt() {
			char c = '\0';
			while (c <= ' ') {
				c = getChar();
			}
			int sign = +1;
			if (c == '+' || c == '-') {
				sign = (c == '+') ? +1 : -1;
				c = getChar();
			}
			unsigned int res = 0;
			while ('0' <= c && c <= '9') {
				res *= 10;
				res += c - '0';
				c = getChar();
			}
			return res * sign;
		}

		FastInput(FILE* f, bool autoClose = true)
			:  bufPtr(buffer), f(f), autoClose(autoClose) {
			buffer[0] = '\0';
		}

		~FastInput() {
			if (autoClose) {
				fclose(f);
			}
		}
};

class FastOutput {
	private:
		static const int bufSize = 1 << 12;
		char buffer[bufSize+1];
		char *bufPtr;
		FILE *f;
		bool autoClose;
	public:
		inline FastOutput& flush() {
			int portion = bufPtr - buffer;
			if (portion == 0) {
				return *this;
			}
			int bytesWritten = fwrite(buffer, 1, portion, f);
			if (bytesWritten != portion) {
				raiseError("Disk write error!!!");
			}
			bufPtr = buffer;
			return *this;
		}
	
		inline FastOutput& putChar(char c) {
			if (bufPtr == buffer + bufSize) {
				flush();
			}
			*(bufPtr++) = c;
			return *this;
		}
		
		inline FastOutput& putChars(const char* c) {
			while (*c != '\0') {
				putChar(*c);
				c++;
			}
			return *this;
		}
		
		inline FastOutput& putString(const string& s) {
			putChars(s.c_str());
			return *this;
		}
		
		inline FastOutput& putInt(int v) {
			unsigned int n = v;
			if (v < 0) {
				putChar('-');
				n = -n;
			}
			char buf[20] = {}, *pos = buf;
			do {
				*(pos++) = (n % 10) + '0';
				n /= 10;
			} while (n != 0);
			do {
				pos--;
				putChar(*pos);
			} while (pos != buf);
			return *this;
		}
		
		inline FastOutput& putLn() {
			putChar('\n');
			return *this;
		}
	
		FastOutput(FILE* f, bool autoClose = true)
			: bufPtr(buffer), f(f), autoClose(autoClose) {
		}

		~FastOutput() {
			flush();
			if (autoClose) {
				fclose(f);
			}
		}
};

int main() {
	FastInput in(stdin, false);
	FastOutput out(stdout, false);
	int n = in.getInt();
	int sumT = 0;
	vector<int> t(n);
	vector< vector<int> > g(n);
	int par = -1;
	for (int i = 0; i < n; i++) {
		int a = in.getInt();
		t[i] = in.getInt();
		sumT += t[i];
		if (a == 0) {
			par = i;
		} else {
			a--;
			g[i].push_back(a);
			g[a].push_back(i);
		}
	}
	if (sumT % 3 != 0) {
		out.putInt(-1).putLn();
		return 0;
	}
	sumT /= 3;
	vector<int> ans;
	function<int(int, int)> dfs = [&](int v, int p) -> int {
		int sz = t[v];
		for (int to: g[v]) {
			if (to == p) {
				continue;
			}
			int add = dfs(to, v);
			if (add == sumT && ans.size() < 2) {
				ans.push_back(to+1);
			} else {
				sz += add;
			}
		}
		return sz;
	};
	int res = dfs(par, -1);
	if (res != sumT || ans.size() != 2) {
		out.putInt(-1).putLn();
	} else {
		out.putInt(ans[0]).putChar(' ').putInt(ans[1]).putLn();
	}
	return 0;
}