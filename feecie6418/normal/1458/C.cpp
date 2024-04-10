#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[1005][1005],n,m,t[1005],H,L,ans[1005][1005],posh[1005][1005],posl[1005][1005];
char str[100005];
struct Thing{
	int array_id,xdlt,ydlt,dlt,isrev;
};
Thing Findposh(int t);
Thing Findposl(int t);
Thing Find(int t);
int main(){
	int tc;
	cin>>tc;
	while(tc--){
		cin>>n>>m;
		for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)scanf("%d",&a[i][j]),posh[i][a[i][j]]=j,posl[a[i][j]][j]=i;
		cin>>str+1;
		Thing t=Find(m);
	//	cout<<t.xdlt<<' '<<t.ydlt<<' '<<t.isrev<<' '<<(char)t.array_id<<' '<<t.dlt<<endl;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				int ti=i,tj=j;
				//if(t.isrev)swap(ti,tj);
				int x=((t.xdlt+ti)%n+n)%n+n,y=((t.ydlt+tj)%n+n)%n+n;
				x=(x-1)%n+1,y=(y-1)%n+1;
				if(t.isrev)swap(x,y);
				int ans;
				if(t.array_id=='p')ans=a[x][y];
				if(t.array_id=='h')ans=posh[x][y];
				if(t.array_id=='l')ans=posl[x][y];
				ans=((ans+t.dlt)%n+n)%n+n;
				ans=(ans-1)%n+1;
				cout<<ans<<' ';
			}
			puts("");
		}
		puts("");
	}
}
Thing Findposh(int t){//ta_{x,?}=y
	Thing tmp;
	if(t==0)return {'h',0,0,0,0};
	if(str[t]=='L'){
		tmp=Findposh(t-1),tmp.dlt--;
		return tmp;
	}
	if(str[t]=='R'){
		tmp=Findposh(t-1),tmp.dlt++;
		return tmp;
	}
	if(str[t]=='U'){
		tmp=Findposh(t-1),tmp.xdlt++;
		return tmp;
	}
	if(str[t]=='D'){
		tmp=Findposh(t-1),tmp.xdlt--;
		return tmp;
	}
	if(str[t]=='I'){
		return Find(t-1);
	}
	if(str[t]=='C'){
		tmp=Findposh(t-1),swap(tmp.xdlt,tmp.ydlt),tmp.isrev^=1;
		return tmp;
	}
}
Thing Findposl(int t){//ta_{?,x}=y
	Thing tmp;
	if(t==0)return {'l',0,0,0,1};
	if(str[t]=='L'){
		tmp=Findposl(t-1),tmp.xdlt++;
		return tmp;
	}
	if(str[t]=='R'){
		tmp=Findposl(t-1),tmp.xdlt--;
		return tmp;
	}
	if(str[t]=='U'){
		tmp=Findposl(t-1),tmp.dlt--;
		return tmp;
	}
	if(str[t]=='D'){
		tmp=Findposl(t-1),tmp.dlt++;
		return tmp;
	}
	if(str[t]=='I'){
		tmp=Findposl(t-1),swap(tmp.xdlt,tmp.ydlt),tmp.isrev^=1;
		return tmp;
	}
	if(str[t]=='C'){
		tmp=Find(t-1),swap(tmp.xdlt,tmp.ydlt),tmp.isrev^=1;
		return tmp;
	}
}
Thing Find(int t){//ta_{x,y}=?
	Thing tmp;
	if(t==0)return {'p',0,0,0,0};
	if(str[t]=='L'){
		tmp=Find(t-1),tmp.ydlt++;
		return tmp;
	}
	if(str[t]=='R'){
		tmp=Find(t-1),tmp.ydlt--;
		return tmp;
	}
	if(str[t]=='U'){
		tmp=Find(t-1),tmp.xdlt++;
		return tmp;
	}
	if(str[t]=='D'){
		tmp=Find(t-1),tmp.xdlt--;
		return tmp;
	}
	if(str[t]=='I'){
		return Findposh(t-1);
	}
	if(str[t]=='C'){
		tmp=Findposl(t-1),swap(tmp.xdlt,tmp.ydlt),tmp.isrev^=1;
		return tmp;
	}
}