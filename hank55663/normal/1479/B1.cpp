#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define pdd pair<double,double>
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define LL long long
#define ULL unsigned long long
#define sqr(x) ((x)*(x))
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;

void solve(){
	int n;
	scanf("%d",&n);
	int a[100005];
	for(int i =0;i<n;i++){
		scanf("%d",&a[i]);
	}
	int sum=0;
	vector<pii> v;
	v.pb(mp(0,2));
	for(int i = 0;i<n;i++){
		if(v.empty()||v.back().x!=a[i])v.pb(mp(a[i],1));
		else v.back().y++;
	}
	v.pb(mp(n+15,2));
	int last=0;
	int tot=0;
	for(int i = 1;i<v.size();i++){
		if(v[i].y>=2){
			if(i-last==1){
				sum+=2;
			//	last=i;
			}
			else if(i-last>=7){
				sum+=i-last-1+2;
				int cnt=0;
				for(int j=last+1;j<i;j++){
					if(v[j].x==v[last].x)cnt++;
				}
				//printf("%d %d\n",cnt,i-last-1);
				if(cnt==(i-last-1)/2&&v[last].x==v[i].x)sum--;
				//last=i;
			}
			else{
				int a=(i-last-1);
				int Max=0;
				for(int j=0;j<(1<<a);j++){
					int x1=v[last].x,x2=v[last].x;
					int sum=0;
					for(int k=0;k<a;k++){
						if(j&(1<<k)){
							if(x1==v[k+last+1].x);
							else{
								x1=v[k+last+1].x;
								sum++;
							}
						}
						else{
							if(x2==v[k+last+1].x);
							else{
								x2=v[k+last+1].x;
								sum++;
							}
						}
					}
					if(x1!=v[i].x)sum++;
					if(x2!=v[i].x)sum++;
					Max=max(Max,sum);
				}
				sum+=Max;
			}
			last=i;
			tot=0;
		}
		else{
			tot++;
		}
		//printf("%d %d\n",sum,v[last].x);
	}
//	sum+=tot;
	printf("%d\n",sum-2);
}
int main(){
    int t=1;//00000;
    //scanf("%d",&t);
    while(t--)solve();
}
/*

*/