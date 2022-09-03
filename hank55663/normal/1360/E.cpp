#include<bits/stdc++.h>
#define mp make_pair
#define x first
#define y second
#define pll pair<LL,LL>
#define pii pair<int,int>
#define LL long long
#define pb push_back
#define pi acos(-1)
#define pdd pair<double,double>
#define MEM(x) memset(x,0,sizeof(x))
#define EPS 1e-7
using namespace std;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        char c[55][55];
        for(int i = 0;i<n;i++){
            scanf("%s",c[i]);
        }
        int ok=1;
        for(int i = 0;i<n-1;i++){
            for(int j=0;j<n-1;j++){
                if(c[i][j]=='1'&&c[i+1][j]=='0'&&c[i][j+1]=='0')ok=0;
            }
        }
        if(ok){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
    }
}
/*
2 11 14
9 3
0 1 2 3
0 1 2 3
0 1 2 3
0 1 2 3
0 1 2 3
3**5+3**5-2**5
000111222
001112220
*/