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
using namespace std;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m,x,y;
        scanf("%d %d %d %d",&n,&m,&x,&y);
        y=min(y,2*x);
        int a=0,b=0;
        for(int i = 0;i<n;i++){
            char c[1005];
            scanf("%s",c);
            int cnt=0;
            for(int j = 0;j<m;j++){
                if(c[j]=='.'){
                    cnt++;
                }
                else{
                    b+=cnt/2;
                    a+=cnt%2;
                    cnt=0;
                }
            }
            b+=cnt/2;
            a+=cnt%2;
        }      
        printf("%d\n",a*x+b*y);
    }
}
/*
2 11 14
9 3


000111222
001112220
*/