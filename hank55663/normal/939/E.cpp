#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define x first
#define y second
#define N 131072
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
LL pre[500005];
int main(){
	int q;
	scanf("%d",&q);
	pre[0]=0;
	vector<int> v;
	while(q--){
		int op;
		scanf("%d",&op);
		if(op==1){
			int x;
			scanf("%d",&x);
			v.pb(x);
			pre[v.size()]=pre[v.size()-1]+x;
		}
		else{
			int Max=v.size(),Min=0;
			while(Max>Min+1){
				int mid=(Max+Min)/2;
				double tot=pre[mid]+v.back();
				tot/=mid+1;
				if(tot+1e-6>=v[mid-1]){
					Min=mid;
				}
				else{
					Max=mid;
				}
			}
			double tot=pre[Min]+v.back();
			tot/=Min+1;
			printf("%.12f\n",v.back()-tot);
		}
	}
}