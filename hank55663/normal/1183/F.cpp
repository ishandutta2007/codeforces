#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define MXN 10005
#define less Less
#define N (1<<20)
typedef complex<double> C;
int main(){
    int q;
    scanf("%d",&q);
    while(q--){
        int n;
        scanf("%d",&n);
        int A[200005];
        set<int> s;
        for(int i = 0;i<n;i++){
            scanf("%d",&A[i]);
            s.insert(A[i]);
        }
        LL ans=*s.rbegin();
        if(ans%2==0&&ans%3==0&&ans%5==0){
           // printf("!\n");
         //   printf("%d %d %d\n",s.find(ans/2)!=s.end(),s.find(ans/3)!=s.end(),s.find(ans/5)!=s.end());
            if(s.find(ans/2)!=s.end()&&s.find(ans/3)!=s.end()&&s.find(ans/5)!=s.end()){
                ans=ans/2+ans/3+ans/5;
                //printf("?\n");
            }
        }
        LL a[3]={0,0,0};
        a[0]=*s.rbegin();
        int now=1;
        while(s.size()){
            if(a[0]%*s.rbegin()==0){
                s.erase(*s.rbegin());
                continue;
            }
            if(now==2){
                if(a[1]%*s.rbegin()==0){
                    s.erase(*s.rbegin());
                    continue;
                }
            }
            a[now++]=*s.rbegin();
            s.erase(*s.rbegin());
            if(now==3)
            break;
        }
        ans=max(ans,a[0]+a[1]+a[2]);
        printf("%lld\n",ans);
    }
}
/*
1 
2 6 
3 5 
4
*/