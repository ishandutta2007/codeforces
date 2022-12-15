#include <bits/stdc++.h>
using namespace std;


int main() {
	int n, perm[305], m[305][305];
	char s[305];
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
	    scanf("%d", &perm[i]);
	}
	memset(m, 0, sizeof(m));
	for(int i = 0; i < n; i++) {
	    scanf("%s", s);
	    for(int j = 0; j < n; j++) {
	        if(s[j] == '1') {
    	        m[i][j] = 1;
	        }
	    }
	}
	for(int i = 0; i < n; i++) {
	    for(int j = 0; j < n; j++) {
	        if(m[i][j] == 1) {
	            for(int a = 0; a < n; a++) {
	                if(m[i][a] == 1 || m[j][a] == 1 || m[a][i] == 1 || m[a][j] == 1) {
	                    m[i][a] = 1;
	                    m[j][a] = 1;
	                    m[a][i] = 1;
	                    m[a][j] = 1;
	                }
	            }
	        }
	    }
	}
	for(int i = 0; i < n; i++) {
	    for(int j = i + 1; j < n; j++) {
	        if(m[i][j] && perm[j] < perm[i]) {
	            swap(perm[j], perm[i]);
	        }
	    }
	}
	for(int i = 0; i < n; i++) {
	    if(i != 0) {
	        printf(" ");
	    }
	    printf("%d", perm[i]);
	}
	return 0;
}