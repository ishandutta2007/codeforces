#include<bits/stdc++.h>
using namespace std;
struct E{
	int x,y,z,id;
};
int n,tot=0;
vector<E> g[2005];
vector<E> Solve(vector<E> G){
	if(G.size()==1)return G;
	vector<E> ret,tmp[1005];
	int d[1005]={0};
	for(auto i:G)d[i.x]++,d[i.y]++,tmp[i.x].push_back(i),tmp[i.y].push_back(i);
	for(int i=1;i<=n;i++){
		if(d[i]!=1)continue;
		int x=tmp[i][0].x,flag=0,val=0,sumval=0,aa=0,bb=0;
		if(x==i)x=tmp[i][0].y;
		map<int,int> vv;
		for(auto &j:tmp[x]){
			if(j.y==x)swap(j.x,j.y);
			if(d[j.y]!=1)flag++,val=j.z;
			else {
				sumval+=j.z;
				if(!aa)aa=j.y;
				else if(!bb)bb=j.y;
				vv[j.y]=j.z;
			}
		}
		if(flag>1)continue;
		if(flag==0){
			if(tmp[x].size()==2){
				if(tmp[x][0].z==tmp[x][1].z)return ret.push_back({tmp[x][0].y,tmp[x][1].y,tmp[x][0].z,++tot}),ret;
				return ret.push_back({-1,-1,-1,++tot}),ret;
			}
			for(int i=2;i<tmp[x].size();i+=3){
				if(i+2==tmp[x].size()){
					int &a=tmp[x][i-2].z,&b=tmp[x][i-1].z,&c=tmp[x][i].z,&d=tmp[x][i+1].z;
					int u=tmp[x][i-2].y,v=tmp[x][i-1].y,w=tmp[x][i].y,o=tmp[x][i+1].y;
					//uw+uo=a-b,uv=b,uw+wo=c,uo+wo=d
					int uv=b,uw=(a-b+c-d)/2,wo=(b-a+c+d)/2,uo=(a-b+d-c)/2;
					ret.push_back({u,v,uv,++tot}),ret.push_back({u,w,uw,++tot}),ret.push_back({o,w,wo,++tot}),ret.push_back({o,u,uo,++tot});
					a=b=c=d=0;
					break;
				}
				if(i+3==tmp[x].size()){
					int &a=tmp[x][i-2].z,&b=tmp[x][i-1].z,&c=tmp[x][i].z,&d=tmp[x][i+1].z,&e=tmp[x][i+2].z;
					int u=tmp[x][i-2].y,v=tmp[x][i-1].y,w=tmp[x][i].y,o=tmp[x][i+1].y,p=tmp[x][i+2].y;
					//uv+vw=b,vw+wo=c,wo+op=d,op+up=e,up+uv=a
					int uv=(a+b-c+d-e)/2,vw=(-a+b+c-d+e)/2,wo=(a-b+c+d-e)/2,op=(-a+b-c+d+e)/2,up=(a-b+c-d+e)/2;
					ret.push_back({u,v,uv,++tot}),ret.push_back({v,w,vw,++tot}),ret.push_back({o,w,wo,++tot}),ret.push_back({o,p,op,++tot}),ret.push_back({u,p,up,++tot});
					a=b=c=d=e=0;
					break;
				}
				int &a=tmp[x][i-2].z,&b=tmp[x][i-1].z,&c=tmp[x][i].z;
				int u=tmp[x][i-2].y,v=tmp[x][i-1].y,w=tmp[x][i].y;
				//uv+uw=a,vw+uv=b,vw+uw=c
				int uv=(a+b-c)/2,vw=(b+c-a)/2,uw=(a+c-b)/2;
				ret.push_back({u,v,uv,++tot}),ret.push_back({u,w,uw,++tot}),ret.push_back({v,w,vw,++tot});
				a=b=c=0;
			}
			return ret;
		}
		//
		vector<E> g;
		map<int,int> mk;
		if(tmp[x].size()==2){
			mk[i]=1;
			if(tmp[x][0].z!=tmp[x][1].z)return ret.push_back({-1,-1,-1,++tot}),ret;
			for(auto i:G)if(!mk[i.x]&&!mk[i.y])g.push_back(i);
			ret=Solve(g);
			if(ret.size()==1&&ret[0].x==-1)return ret;
			for(auto &ii:ret){
				if(ii.x==x)ii.x=i;
				if(ii.y==x)ii.y=i;
			}
			return ret;
		}
		int t=(val-sumval)/2;
		for(auto j:tmp[x])if(d[j.y]==1)mk[j.y]=1;
		for(auto i:G)if(!mk[i.x]&&!mk[i.y])g.push_back(i);
		auto rr=Solve(g);
		if(rr.size()&&rr[0].x==-1)return rr;
		int P=0,Q=0,ww=0;
		for(auto &ii:rr){
			if(ii.y==x)swap(ii.x,ii.y);
			if(ii.x==x)P=ii.y,Q=ii.z,ww=ii.id;
			else ret.push_back(ii);
		}
		ret.push_back({aa,bb,-t,++tot}),vv[aa]+=t,vv[bb]+=t;
		for(auto j:tmp[x])if(d[j.y]==1&&j.y!=aa)ret.push_back({P,j.y,vv[j.y],++tot}),Q-=vv[j.y];
		for(auto &ii:rr)if(ii.x==x)ret.push_back({ii.y,aa,ii.id==ww?Q:ii.z,++tot});
		return ret;
	}
	assert(0);
	return ret;
}
int main(){
	cin>>n,srand(time(0));
	vector<E> tmp;
	for(int i=1,x,y,z;i<n;i++)cin>>x>>y>>z,tmp.push_back({x,y,z,++tot});
	auto i=Solve(tmp);
	if(i.size()==1&&i[0].x==-1)puts("NO");
	else {
		puts("YES"),cout<<i.size()<<'\n',assert(i.size()<=n+1);
		for(auto j:i)cout<<j.x<<' '<<j.y<<' '<<j.z<<'\n';
	}
}