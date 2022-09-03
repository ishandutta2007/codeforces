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
        int n,m,a,b;
        scanf("%d %d %d %d",&n,&m,&a,&b);
        if(n*a==b*m){
            queue<int> q;
            for(int i = 0;i<m;i++)q.push(i);
            int ans[55][55];
            MEM(ans);
            for(int i = 0;i<n;i++){
                for(int j =0;j<a;j++){
                    ans[i][q.front()]=1;
                    q.push(q.front());
                    q.pop();
                }
            }
            printf("YES\n");
            for(int i =  0;i<n;i++){
                for(int j =0;j<m;j++){
                    printf("%d",ans[i][j]);
                }
                printf("\n");
            }
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