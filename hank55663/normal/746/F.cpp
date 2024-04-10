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
int main(){
    int n,w,k;
    scanf("%d %d %d",&n,&w,&k);
    int a[200005];
    for(int i = 1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    int t[200005];
    for(int i = 1;i<=n;i++){
        scanf("%d",&t[i]);
    }
    int r=1;
    set<pii> s1,s2;
    int ans=0;
    int sum=0;
    int tot=0;
    for(int i = 1;i<=n;i++){
       // printf("%d\n",sum);
        while(1){
            if(sum>k)break;
            ans=max(ans,tot);
            if(r>n)
            break;
            if(s2.size()<w){
                sum+=(t[r]+1)/2;
                tot+=a[r];
                s2.insert(mp(t[r],r));
            }
            else if(s2.begin()->x<t[r]){
                sum+=(t[r]+1)/2;
                tot+=a[r];
                s2.insert(mp(t[r],r));
                s1.insert(*s2.begin());
                sum+=(s2.begin()->x)/2;
                s2.erase(s2.begin());
            }
            else{
                sum+=t[r];
                tot+=a[r];
                s1.insert(mp(t[r],r));
            }
            r++;
        }
        if(s1.find(mp(t[i],i))!=s1.end()){
            s1.erase(mp(t[i],i));
            sum-=t[i];
            tot-=a[i];
        }
        else{
            s2.erase(mp(t[i],i));
            sum-=(t[i]+1)/2;
            tot-=a[i];
            if(s1.size()){
                s2.insert(*s1.rbegin());
                sum-=(s1.rbegin()->x)/2;
                s1.erase(*s1.rbegin());
            }
        }
    }
    printf("%d\n",ans);
}
/*
4
8
2 2 4
3 1 3 5
1 2
2 1 5
4 2 6 4 7
2 5 8
2 8 5
2 7 6
 */