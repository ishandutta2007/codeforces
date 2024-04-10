#include <bits/stdc++.h>
using namespace std;
int n,a[500005],b[500005],P,Q;
char s[500005];
int mxlx,mxly,mirx,miry,mxldif,mirdif;
bool Check(){
	P=max(P,0),Q=max(Q,0);
	if(P<mxlx||P>mirx||Q<mxly||Q>miry||Q-P<mxldif||Q-P>mirdif||(P==0&&Q==0))return 0;
	return 1;
}
bool Check(int mid){
	mxlx=-2e8,mxly=-2e8,mirx=2e8,miry=2e8,mxldif=-2e8,mirdif=2e8;//x,y,y-x
	for(int i=1;i<=n;i++){
		mxlx=max(mxlx,a[i]-mid);
		mxly=max(mxly,b[i]-mid);
		mxldif=max(mxldif,b[i]-mid-a[i]);
		mirx=min(mirx,a[i]+mid);
		miry=min(miry,b[i]+mid);
		mirdif=min(mirdif,b[i]+mid-a[i]);
	}
	if(mxlx>mirx||mxly>miry||mxldif>mirdif)return 0;
	if(mxldif>miry-mxlx)return 0;
	if(mirdif<mxly-mirx)return 0;
	P=mxlx,Q=mxly;if(Check())return 1;
	P=mirx,Q=mxly;if(Check())return 1;
	P=mxlx,Q=miry;if(Check())return 1;
	P=mirx,Q=miry;if(Check())return 1;
	P=mxlx,Q=P+mxldif;if(Check())return 1;
	P=mirx,Q=P+mxldif;if(Check())return 1;
	P=mxlx,Q=P+mirdif;if(Check())return 1;
	P=mirx,Q=P+mirdif;if(Check())return 1;
	Q=mxly,P=Q-mxldif;if(Check())return 1;
	Q=miry,P=Q-mxldif;if(Check())return 1;
	Q=mxly,P=Q-mirdif;if(Check())return 1;
	Q=miry,P=Q-mirdif;if(Check())return 1;
	P=0,Q=1;if(Check())return 1;
	P=1,Q=0;if(Check())return 1;
	P=1,Q=1;if(Check())return 1;
	assert(0);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%s",s);
		int l=strlen(s);
		for(int j=0;j<l;j++)if(s[j]=='B')a[i]++;else b[i]++;
	}
	int l=0,r=1e7,ans=1e7;
	while(l<=r){
		int mid=(l+r)/2;
		if(Check(mid))ans=mid,r=mid-1;
		else l=mid+1;
	}
	cout<<ans<<'\n',Check(ans);
	for(int i=1;i<=P;i++)cout<<'B';
	for(int i=1;i<=Q;i++)cout<<'N';
}