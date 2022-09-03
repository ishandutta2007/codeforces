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
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    char c[100005];
    scanf("%s",c);
    vector<int> v[2];
    for(int i =0;c[i]!=0;i++){
        v[c[i]-'0'].pb(i);
    }
    if(v[0].empty()||v[1].empty()){
        printf("tokitsukaze\n");
    }
    else if(v[0].back()-v[0].front()+1<=k||v[1].back()-v[1].front()+1<=k){
        printf("tokitsukaze\n");
    }
    else{
        for(int i = 0;i<=n-k;i++){
            int l0=v[0].front(),r0=v[0].back();
            int l1=v[1].front(),r1=v[1].back();
            if(l0>=i)l0=i;
            if(r0<=i+k-1)r0=i+k-1;
            if(l1>=i)l1=*upper_bound(v[1].begin(),v[1].end(),i+k-1);
            if(r1<=i+k-1)r0=*(lower_bound(v[1].begin(),v[1].end(),i)-1);
            if(r0-l0+1>k&&r1-l1+1>k){
              //  printf("%d0 %d %d %d %d\n",i,r0,l0,r1,l1);
                printf("once again\n");
                return 0;
            }
            l0=v[0].front(),r0=v[0].back();
            l1=v[1].front(),r1=v[1].back();
            if(l1>=i)l1=i;
            if(r1<=i+k-1)r1=i+k-1;
            if(l0>=i)l0=*upper_bound(v[0].begin(),v[0].end(),i+k-1);
            if(r0<=i+k-1)r0=*(lower_bound(v[0].begin(),v[0].end(),i)-1);
            if(r0-l0+1>k&&r1-l1+1>k){
              //  printf("%d1 %d %d %d %d\n",i,r0,l0,r1,l1);
                printf("once again\n");
                return 0;
            }
        }
        printf("quailty\n");

    }
}
/*
1 
2 6 
3 5 
4
*/