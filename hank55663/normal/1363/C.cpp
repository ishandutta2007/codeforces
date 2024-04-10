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
vector<int> v[1005];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,x;
        scanf("%d %d",&n,&x);
        for(int i =  1;i<=n;i++)v[i].clear();
        for(int i = 1;i<n;i++){
            int x,y;
            scanf("%d %d",&x,&y);
            v[x].pb(y);
            v[y].pb(x);
        }
        if(v[x].size()==1||n==1)
        printf("Ayush\n");
        else{
            if(n%2==0){
                printf("Ayush\n");
            }
            else{
                printf("Ashish\n");
            }
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