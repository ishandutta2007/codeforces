#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned long long
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
#define less Less
#define EPS 1e-4
#define arg ARG
#define pdd pair<double,double>
#define cpdd const pdd
int main(){
    int n;
    scanf("%d",&n);
    int a[2005];
    for(int i = 0;i<n;i++){
        scanf("%d",&a[i]);
    }
    set<int> tmp;
    int ans=n;
    for(int i = 0;i<n;i++){
        set<int> s=tmp;
        for(int j = n-1;j>=i;j--){
            if(s.find(a[j])==s.end()){
                s.insert(a[j]);
            }
            else{
                ans=min(ans,j-i+1);
                break;
            }
        }
        if(tmp.find(a[i])!=tmp.end()){
            break;
        }
        tmp.insert(a[i]);
    }
    if(tmp.size()==n)ans=0;
    printf("%d\n",ans);
}