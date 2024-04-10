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
    int n;
    scanf("%d",&n);
    int a[100005];
    for(int i = 0;i<n;i++){
        scanf("%d",&a[i]);
    }
    sort(a,a+n);
    int tot=0;
    int ok=1;
    for(int i = 0;i<n;i++){
        if(a[i]>=i){
            tot+=a[i]-i;
        }
        else{
            ok=0;
        }
    }
    map<int,int> m;
    for(int i = 0;i<n;i++)
        m[a[i]]++;
    int ok2=0;
    for(int i = 0;i<n;i++){
        if(a[i]!=0){
            if(--m[a[i]]==0){
                m.erase(a[i]);
            }
            m[a[i]-1]++;
            if(m.size()==n){
                ok2=1;
            }
            if(--m[a[i]-1]==0){
                m.erase(a[i]-1);
            }
            m[a[i]]++;
        }
    }
    if(!ok2)ok=0;
    if(tot%2==0)ok=0;
    if(ok)printf("sjfnb\n");
    else printf("cslnb\n");
}
/*
1 
2 6 
3 5 
4
*/