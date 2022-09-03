#include <bits/stdc++.h>
#define LL long long
#define pb push_back
#define x first
#define y second
#define mp make_pair
#define pii pair<int,int>
using namespace std;

int main() {

    int t;
    scanf("%d",&t);
    pii p[200005];
    while(t--){
        LL n,s;
        scanf("%lld %lld",&n,&s);
        vector<int> v1,v2;
        for(int i = 0;i<n;i++){
            int x,y;
            scanf("%d %d",&x,&y);
            p[i]=mp(x,y);
            v1.pb(x);
            v2.pb(y);
        }
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        sort(p,p+n);
        int Min=v1[n/2],Max=v2[n/2]+1;
        while(Min+1<Max){
            int mid=(Max+Min)/2;
            LL tot=0,sum=0;
            for(int i = 0;i<n;i++){
                if(p[i].y<mid){
                    tot+=p[i].x,sum++;
                }
            }
            for(int i = 0;i<n;i++){
                if(p[i].y>=mid){
                    if(sum!=n/2){
                        sum++;
                        tot+=p[i].x;
                    }
                    else{
                        tot+=max(p[i].x,mid);
                    }
                }
            }
           // printf("%lld %d\n",tot,mid);
            if(tot>s){
                Max=mid;
            }
            else{
                Min=mid;
            }
        }
        int ans=0;
        for(int i = 0;i<n;i++){
            if(p[i].x<=Min){
                ans=max(ans,min(p[i].y,Min));
            }
        }
        printf("%d\n",ans);
    }
	return 0;
}