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
        int n,k;
        scanf("%d %d",&n,&k);
          vector<int> v[1005];
         for(int i = 0;i<k;i++){
            int x;
            scanf("%d",&x);
            while(x--){
                int y;
                scanf("%d",&y);
                v[i].pb(y);
            }
        }
        int l=1,r=n;
        printf("? %d",n);
      
       
        for(int i = 1;i<=n;i++){
            printf(" %d",i);
        }
        printf("\n");
        fflush(stdout);
        int Max;
        scanf("%d",&Max);
        while(l!=r){
            int mid=(l+r)/2;
            printf("? %d",(mid-l+1));
            for(int i = l;i<=mid;i++){
                printf(" %d",i);
            }
            printf("\n");
            fflush(stdout);
            int x;
            scanf("%d",&x);
            if(x==Max)r=mid;
            else l=mid+1;
        }
        vector<int> ans;
        for(int i =0;i<k;i++){
            sort(v[i].begin(),v[i].end());
            int need=0;
            for(auto it:v[i]){
                if(it==l)need=1;
            }
            if(!need)ans.pb(Max);
            else{
                set<int> s;
                for(int j = 1;j<=n;j++)s.insert(j);
                for(auto it:v[i]) s.erase(it);
                printf("? %d",s.size());
                for(auto it:s){
                    printf(" %d",it);
                }
                printf("\n");
                fflush(stdout);
                int x;
                scanf("%d",&x);
                ans.pb(x);
            }
        }
        printf("!");
        for(auto it:ans){
            printf(" %d",it);
        }
        printf("\n");
        fflush(stdout);
        char c[1005];
        scanf("%s",c);
        if(c[0]=='I')assert(0);
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