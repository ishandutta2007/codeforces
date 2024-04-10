#include <bits/stdc++.h>

#define N 2000020

using namespace std;

int t, n, lens[N];
string s;

void manacher() {
  int m = 2*n + 1;
  int C = -1, R = 0;

  for(int i = 0; i <= m; i++) {
    lens[i] = 0;
  }

  for (int i = 0; i < m; i++) {
    int mirror = 2*C-i;
    int diff = R - i;

    if(diff > 0) lens[i] = min(lens[mirror], diff);

    while (i + lens[i] < m && i - lens[i] > 0) {
      if ((i + lens[i] + 1) % 2 == 0) lens[i]++;
      else if (s[(i+lens[i]+1)/2] == s[(i-lens[i]-1)/2]) lens[i]++;
      else break;
    }

    if (i + lens[i] > R) {
      C = i;
      R = i + lens[i];
    }
  }
}

char ss[N];

int main() {
    scanf("%d", &t);

    while(t--) {
        scanf("%s", ss);
        s = ss;
        n = s.size();

        manacher();

        int i = 0, j = n-1;
        while(i < j && s[i] == s[j]) {
            i++;
            j--;
        }

        int more = 0, lft = 0;
        for(int c = 0; c <= 2*n; c++) {
            if(2*i+1 <= c && c <= 2*j+1) {
                int ret = lens[c] - 1;
                if(2*i + 1 >= c - ret || c + ret >= 2*j+1) {
                    int dist = min(c - (2*i+1), (2*j+1) - c);
                    if(more < dist + 1) {
                        more = dist + 1;
                        lft = (c - dist == (2*i+1));
                    }
                }
            }
        }

        for(int k = 0; k < i; k++) printf("%c", s[k]);
        if(lft)  for(int k = 0; k < more; k++) printf("%c", s[k+i]);
        if(!lft) for(int k = more-1; k >= 0; k--) printf("%c", s[j-k]);
        for(int k = j+1; k < n; k++) printf("%c", s[k]);
        puts("");
    }

    return 0;
}