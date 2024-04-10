#include <bits/stdc++.h>

#define MN 1001000
#define w1 while(1)
#define debug(a) cout << a << endl
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;

int n, a[55][55], possible = 1;
//char s[MN]; string str;

int main() {
    scanf("%d", &n);

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            scanf("%d",&a[i][j]);

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            if(a[i][j] != 1) {
                int flag = 0;
                for(int k=0; k<n; k++) {
                    int rowelem = a[k][j];
                    for(int l=0; l<n; l++) {
                        int colelem = a[i][l];
                        if(rowelem + colelem == a[i][j]) flag = 1;
                    }
                }
                if(flag == 0) {
                    printf("No\n");
                    return 0;
                }
            }

    printf("Yes\n");
    return 0;
}