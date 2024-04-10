#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr; 
int n;
map<int,int> f[100005],A[100005],B[100005];
int G(int x,int y){
	if(x+y<=2)return 0;
	if(x==2&&y==1)return 1;
	if(x==1&&y==2)return 2;
	if(x+y<=3)return 3;
	if(f[x].count(y))return f[x][y];
	if(x>=30||y>=30){
		int u=(x+1)/2,v=(y+1)/2;
		return f[x][y]=max(G(y-v,u+v),G(v,x-u+y-v))+1;
	}
	f[x][y]=1e9;
	for(int i=0;i<=x;i++){
		for(int j=0;j<=y;j++){
			int u=i,v=j;
			if(i==0||i==x){
				if((y-v<=1&&u+v>1)||(v<=1&&x-u+y-v>1))continue;
			}
			int w=max(G(y-v,u+v),G(v,x-u+y-v))+1;
			if(w<f[x][y])f[x][y]=w,A[x][y]=i,B[x][y]=j;
		}
	}
	//cout<<x<<' '<<y<<' '<<f[x][y]<<'\n';
	return f[x][y];
}
void Ans(int x){
	cout<<"! "<<x<<endl;
	string s;
	cin>>s;
	if(s==":(");
	else exit(0);
}
typedef basic_string<int> ve;
bool Ask(ve x){
	cout<<"? "<<x.size()<<' ';
	for(int i:x)cout<<i<<' ';
	cout<<endl;
	string s;
	cin>>s;
	if(s=="YES")return 1;
	return 0;
}
void Solve(basic_string<int> v1,basic_string<int> v2){
	if(v1.size()+v2.size()<=2){
		for(int i:v1)Ans(i);
		for(int i:v2)Ans(i);
		return ;
	}
	if(v1.size()==2&&v2.size()==1){
		Ans(v2[0]);
		int w1=Ask((ve){v1[0]});
		if(w1)Ans(v1[0]);
		else Ans(v1[1]);
		return ;
	}
	if(v1.size()==1&&v2.size()==2){
		int w1=Ask(v2);
		if(w1)Ans(v2[0]),Ans(v2[1]);
		else {
			int w2=Ask((ve){v2[0]});
			if(w2)Ans(v1[0]),Ans(v2[0]);
			else Ans(v1[0]),Ans(v2[1]);
		}
		return ;
	}
	if(v1.size()+v2.size()<=3){
		vector<int> u;
		for(int i:v1)u.push_back(i);
		for(int i:v2)u.push_back(i);
		int w0=Ask((ve){u[0]});
		if(w0){
			Ans(u[0]);
			int w1=Ask((ve){u[1]});
			if(w1)Ans(u[1]);
			else Ans(u[2]);
		}
		else {
			int w1=Ask((ve){u[1],u[2]});
			if(w1){
				Ans(u[1]);
				Ans(u[2]);
			}
			else {
				int w2=Ask((ve){u[1]});
				if(w2)Ans(u[0]),Ans(u[1]);
				else Ans(u[0]),Ans(u[2]);
			}
		}
		return ;
	}
	int u,v;
	if(v1.size()>=30||v2.size()>=30){
		u=(v1.size()+1)/2;
		v=(v2.size()+1)/2;
	}
	else {
		u=A[v1.size()][v2.size()];
		v=B[v1.size()][v2.size()];
	}
	ve t;
	for(int i=0;i<u;i++)t+=v1[i];
	for(int i=0;i<v;i++)t+=v2[i];
	if(Ask(t)){
		ve n1,n2;
		for(int i=v;i<v2.size();i++)n1+=v2[i];
		n2=t;
		Solve(n1,n2);
	}
	else {
		ve n1,n2;
		for(int i=0;i<v;i++)n1+=v2[i];
		for(int i=u;i<v1.size();i++)n2+=v1[i];
		for(int i=v;i<v2.size();i++)n2+=v2[i];
		Solve(n1,n2);
	}
}
int main(){
	/*int s1=0,s2=100000;
	for(int i=1;i<=53;i++){
		int x=(s1+1)/2,y=(s2+1)/2;
		s1=s2-y,s2=x+y;
		cout<<s1<<' '<<s2<<'\n';
	}*/
	cin>>n,G(0,n);
	basic_string<int> v1,v2;
	for(int i=1;i<=n;i++)v2.push_back(i);
	Solve(v1,v2);
}