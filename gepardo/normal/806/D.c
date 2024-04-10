#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BUF_SIZE 4096
#define MAX_N 2000
#define LL_INF 123456789012345678LL
#define INF 1234567890

inline static char getChar() {
	static char buffer[BUF_SIZE+1] = {'\0'};
	static char *bufPtr = buffer;
	if (*bufPtr == '\0') {
		int bytesRead = fread(buffer, sizeof(char), BUF_SIZE, stdin);
		buffer[bytesRead] = '\0';
		bufPtr = buffer;
	}
	if (*bufPtr == '\0') {
		return '\0';
	} else {
		return *(bufPtr++);
	}
}

inline static int getInt() {
	char c = '\0';
	while (c <= ' ') {
		c = getChar();
	}
	int sign = +1;
	if (c == '+' || c == '-') {
		sign = (c == '+') ? +1 : -1;
		c = getChar();
	}
	unsigned res = 0;
	while ('0' <= c && c <= '9') {
		res *= 10;
		res += c - '0';
		c = getChar();
	}
	return res * sign;
}

inline static void putInt(long long v) {
	unsigned long long n = v;
	if (v < 0) {
		putchar('-');
		n = -n;
	}
	char buf[20] = {}, *pos = buf;
	do {
		*(pos++) = (n % 10) + '0';
		n /= 10;
	} while (n != 0);
	do {
		pos--;
		putchar(*pos);
	} while (pos != buf);
}

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

int main() {
	static int a[MAX_N][MAX_N];
	static bool used[MAX_N];
	static long long d[MAX_N];
	int n = getInt();
	int minVal = INF;
	for (int i = 0; i < n; i++) {
		a[i][i] = INF;
		for (int j = i+1; j < n; j++) {
			a[i][j] = a[j][i] = getInt();
			minVal = min(minVal, a[i][j]);
		}
	}
	for (int i = 0; i < n; i++) {
		used[i] = false;
		d[i] = LL_INF;
	}
	for (int i = 0; i < n; i++) {
		int minOnRow = INF;
		for (int j = 0; j < n; j++) {
			if (i == j) {
				continue;
			}
			a[i][j] -= minVal;
			if (a[i][j] == 0) {
				d[i] = d[j] = 0;
			}
			minOnRow = min(minOnRow, a[i][j]);
		}
		for (int j = 0; j < n; j++) {
			a[i][j] = min(a[i][j], 2 * minOnRow);
		}
		a[i][i] = 0;
	}
	for (int i = 0; i < n; i++) {
		int v = 0;
		while (used[v]) {
			v++;
		}
		for (int j = v+1; j < n; j++) {
			if (!used[j] && d[j] < d[v]) {
				v = j;
			}
		}
		used[v] = true;
		for (int j = 0; j < n; j++) {
			if (!used[j]) {
				d[j] = min(d[j], d[v] + a[j][v]);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		putInt(d[i] + (long long)(n-1) * minVal);
		putchar('\n');
	}
	return 0;
}