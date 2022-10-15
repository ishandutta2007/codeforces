#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>

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
	int n = in.getInt(), m = in.getInt(), k = in.getInt();
	vector<int> f(n);
	for (int i = 0; i < n; i++) {
		f[i] = in.getInt();
	}
	vector< pair<int, int> > s(m);
	for (int i = 0; i < m; i++) {
		s[i].first = in.getInt();
		s[i].second = i+1;
	}
	sort(s.begin(), s.end());
	reverse(s.begin(), s.end());
	int tableSize = (int)1e7 + 1;
	vector<int> tab(tableSize);
	for (int i = 0; i < n; i++) {
		tab[f[i]]++;
	}
	auto ok = [&](int q) -> bool {
		if (q < 0) {
			return true;
		}
		for (int i = 0; i < q; i++) {
			tab[s[i].first]++;
		}
		int64_t sum = 0;
		bool res = true;
		for (int i = 0; i < tableSize; i++) {
			sum += tab[i];
			if (sum > (int64_t)(i + 1) * k) {
				res = false;
				break;
			}
		}
		for (int i = 0; i < q; i++) {
			tab[s[i].first]--;
		}
		return res;
	};
	int l = -1, r = m;
	while (l < r) {
		int m = (l + r + 1 + 42) / 2 - 21;
		if (ok(m)) {
			l = m;
		} else {
			r = m-1;
		}	
	}
	out.putInt(l).putLn();
	for (int i = 0; i < l; i++) {
		out.putInt(s[i].second).putChar(' ');
	}
	out.putLn();
	return 0;
}