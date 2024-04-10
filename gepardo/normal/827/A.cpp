// Who needs long templates? :)
//    ? :)

/*---------------------------------+
|  Codeforces Round #423 (Div. 1)  |
+----------------------------------+
|             Problem A            |
+---------------------------------*/

#include <bits/stdc++.h>

using namespace std;

const int infinity = 1234567890;
const long double eps = 1e-8;

mt19937_64 randGen(chrono::system_clock().now().time_since_epoch().count());

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
				int bytesRead = fread(buffer, sizeof(char), bufSize, f);
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
		
		inline int64_t getInt() {
			char c = '\0';
			while (c <= ' ') {
				c = getChar();
			}
			int64_t sign = +1;
			if (c == '+' || c == '-') {
				sign = (c == '+') ? +1 : -1;
				c = getChar();
			}
			uint64_t res = 0;
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
			int bytesWritten = fwrite(buffer, sizeof(char), portion, f);
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
		
		inline FastOutput& putInt(int64_t v) {
			uint64_t n = v;
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

FastInput fin(stdin);
FastOutput fout(stdout);

const int LIMIT = (int)2e6 + 42;

int main() {
	ios_base::sync_with_stdio(false);
	int n = fin.getInt();
	set<int> s;
	for (int i = 0; i < LIMIT; i++) {
		s.insert(i);
	}
	string res(LIMIT, '?');
	for (int i = 0; i < n; i++) {
		string q = fin.getToken();
		int len = q.size();
		int k = fin.getInt();
		for (int j = 0; j < k; j++) {
			int p = fin.getInt() - 1;
			for (int k = p; k < p + len; ) {
				if (s.count(k)) {
					s.erase(k);
					res[k] = q[k - p];
					k++;
				} else {
					k = *s.lower_bound(k);
				}
			}
		}
	}
	while (res.back() == '?') {
		res.pop_back();
	}
	for (char &c : res) {
		if (c == '?') {
			c = 'a';
		}
	}
	fout.putString(res).putLn();
	return 0;
}