#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
const db eps=1e-8;
struct point{db x,y;void in(){cin>>x>>y;}}a[12];
db Dot(point x,point y){return x.x*y.x+x.y*y.y;}
db Cross(point x,point y){return x.x*y.y-x.y*y.x;}
db Dis(point x,point y){return sqrt((x.x-y.x)*(x.x-y.x)+(x.y-y.y)*(x.y-y.y));}
point operator +(point x,point y){return {x.x+y.x,x.y+y.y};}
point operator -(point x,point y){return {x.x-y.x,x.y-y.y};}
point operator *(db x,point y){return {x*y.x,x*y.y};}
point operator *(point y,db x){return {x*y.x,x*y.y};}
// 
point Rotate(point x,db y){return {x.x*cos(y)-x.y*sin(y),x.y*cos(y)+x.x*sin(y)};}
struct triangle{db l[3];db &operator [](const int k){return l[k];}}t[4];
int f[20],ff[20],m;
vector<point> Findp(point x,point y,db r1,db r2){
	db dis=Dis(x,y),len[5]={dis,r1,r2};
	vector<point> ret;
	if(fabs(dis-r1-r2)<eps){
		ret.push_back(x+(y-x)*(r1/dis));
		ret.push_back(x+(y-x)*(r2/dis));
		return ret;
	}
	if(r1<r2)swap(r1,r2);
	if(fabs(r1-dis-r2)<eps){
		ret.push_back(x+(x-y)*(r2/dis));
		ret.push_back(y+(y-x)*(r2/dis));
		return ret;
	}
	db ang=acos((dis*dis+r1*r1-r2*r2)/(2*dis*r1));
	point t=Rotate(y-x,ang);
	ret.push_back(x+t*(r1/dis));
	t=Rotate(y-x,-ang);
	ret.push_back(x+t*(r1/dis));
	//cout<<r1<<' '<<r2<<' '<<dis<<' '<<ang<<'\n';
	//assert(fabs(ret.back().x)<50);
	if(fabs(r1-r2)>eps){
		t=Rotate(x-y,ang);
		ret.push_back(y+t*(r1/dis));
		t=Rotate(x-y,-ang);
		ret.push_back(y+t*(r1/dis));
	}
	return ret;
}
void Add(point o){
	for(int i=1;i<=m;i++)if(fabs(o.x-a[i].x)<eps&&fabs(o.y-a[i].y)<eps)return ;
	a[++m]=o;
}
void dfs(int cur,int to){
	if(m>=ff[to])return ;
//	cout<<cur<<' '<<to<<'\n';
//	for(int i=1;i<=m;i++){
//		printf("(%.5lf %.5lf)\n",a[i].x,a[i].y);
//	}
//	puts("");
	if(cur==to)return ff[to]=min(ff[to],m),void();
	for(int i=0;i<4;i++){
		if((cur&(1<<i))||!(to&(1<<i)))continue;
		for(int j=0;j<3;j++){
			for(int k=1;k<=m;k++){
				for(int l=k+1;l<=m;l++){
					if(fabs(Dis(a[k],a[l])-t[i][j])>eps)continue;
					int tm=m,p,q;
					if(j==0)p=1,q=2;
					else if(j==1)p=0,q=2;
					else p=0,q=1;
					auto vec=Findp(a[k],a[l],t[i][p],t[i][q]);
					for(auto o:vec)Add(o),dfs(cur|(1<<i),to),m=tm;
				}
			}
		}
	}
}
void Solve(int S){
	for(int i=0;i<4;i++){
		if(!(S&(1<<i)))continue;
		for(int j=i+1;j<4;j++){
			if(!(S&(1<<j)))continue;
			for(int k=j+1;k<4;k++){
				if(!(S&(1<<k)))continue;
				for(int p=0;p<3;p++){
					for(int q=0;q<3;q++){
						for(int r=0;r<3;r++){
							db len[5]={t[i][p],t[j][q],t[k][r]};
							sort(len,len+3);
							if(len[0]+len[1]+eps<len[2])continue;
							m=0,a[++m]={0,0},a[++m]={0,len[0]};
							//cout<<"PP1 "<<S<<' '<<ff[S]<<'\n';
							auto vec=Findp(a[1],a[2],len[1],len[2]);
							a[++m]=vec[0],dfs(0,S);
							//cout<<"PP "<<S<<' '<<ff[S]<<'\n';
						}
					}
				}
			}
		}
		m=0,a[++m]={0,0},a[++m]={0,t[i][0]};
		auto vec=Findp(a[1],a[2],t[i][1],t[i][2]);
		a[++m]=vec[0],dfs(1<<i,S);
		//cout<<"PP "<<S<<' '<<ff[S]<<'\n';
	}
}
int main(){
	memset(f,0x3f,sizeof(f)),memset(ff,0x3f,sizeof(ff)),f[0]=0;
	for(int i=0;i<4;i++){
		point x,y,z;
		x.in(),y.in(),z.in();
		t[i][0]=Dis(x,y),t[i][1]=Dis(x,z),t[i][2]=Dis(y,z);
	}
//	Solve(3);
//	return 0;
	for(int i=1;i<16;i++)Solve(i);
	for(int i=1;i<16;i++)for(int j=i;j;j=(j-1)&i)f[i]=min(f[i],f[i-j]+ff[j]-(bool)(i-j));
	int u=9;
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			for(int k=0;k<3;k++){
				for(int l=0;l<3;l++){
					db len[5]={t[0][i],t[1][j],t[2][k],t[3][l]};
					sort(len,len+4);
					if(len[0]+len[1]+len[2]+eps>len[3])u=8;
				}
			}
		}
	}
	cout<<min(f[15],u);
}