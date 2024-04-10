#pragma comment(linker, "/STACK:100000000")
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <ctime>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <list>
#include <deque>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define taskname "task_d"

const double pi = acos(-1.0);

const int size = 4000;
const int bitsize = size / 32;
const int inf = 1000 * 1000 * 1000;

int n;
char buf[size];

unsigned int bits[size][bitsize];
int num[size];
unsigned int used[size][bitsize];
int numlen;

int main() {
	//assert(freopen("input.txt", "r", stdin));
	//assert(freopen("output.txt", "w", stdout));
	
	int mxcur = 0;

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", buf);

		int len = strlen(buf);
		reverse(buf, buf + len);
		numlen = (len + 8) / 9;
		for (int j = 0; j < len; j += 9) {
			num[j / 9] = 0;
			int curlen = min(len - j, 9);
			int h = 1;
			for (int k = 0; k < curlen; k++) {
				num[j / 9] += (buf[j + k] - '0') * h;
				h *= 10;
			}
		}


		int cur = 0;
		while (numlen > 0) {
			bits[i][cur / 32] += (1u << (cur & 31)) * (num[0] & 1);
			cur++;

			for (int j = numlen - 1; j >= 0; j--) {
				if (j > 0)
					num[j - 1] += (num[j] & 1) * inf;
				num[j] = num[j] >> 1; 
			}
			while (numlen > 0 && num[numlen - 1] == 0)
				numlen--;
		}

		mxcur = max(mxcur, cur);
	}
	
	int bitsmx = (mxcur + 31) / 32;
	int rank = 0;
	for (int i = 0; i < n; i++)
		used[i][i / 32] ^= (1u << (i & 31));
	for (int i = 0; i < n; i++) {
		bool flag = false;
		for (int j = 0; j < mxcur; j++) {
			if ((bits[i][j / 32] >> (j & 31)) & 1) {
				flag = true;

				for (int k = i + 1; k < n; k++)
					if ((bits[k][j / 32] >> (j & 31)) & 1) {
						for (int p = 0; p < bitsmx; p++)
							used[k][p] ^= used[i][p];
						//cout << i << ' ' << k << endl;

						for (int p = 0; p < bitsmx; p++)
							bits[k][p] ^= bits[i][p];
					}

				break;
			}
		}

		if (flag) {
			printf("0\n");
		} else {
			int cnt = 0;
			for (int j = 0; j < n; j++)
				if (j != i)
					cnt += (used[i][j / 32] >> (j & 31)) & 1;
			printf("%d", (int) cnt);
			for (int j = 0; j < n; j++)
				if ((j != i) && (used[i][j / 32] >> (j & 31)) & 1)
					printf(" %d", j);
			printf("\n");
		}
	}

	return 0;
}