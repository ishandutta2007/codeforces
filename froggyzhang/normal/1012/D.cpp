#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
#define N 200020
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int n,m,ax[N],bx[N],tot;
char a[N],b[N];
vector<pair<int,int> > A,B,ans;
bool flag;
inline pair<int,int> getA(){
	pair<int,int> tmp=A.back();
	A.pop_back();
	return tmp;
}
inline pair<int,int> getB(){
	pair<int,int> tmp=B.back();
	B.pop_back();
	return tmp;
}
int main(){
	scanf("%s",a+1);
	scanf("%s",b+1);
	n=strlen(a+1),m=strlen(b+1);
	A.push_back(make_pair(a[n]-'a',1));
	B.push_back(make_pair(b[m]-'a',1));
	for(int i=n-1;i>=1;--i){
		if(a[i]-'a'==A.back().first)++A.back().second;
		else A.push_back(make_pair(a[i]-'a',1));
	}
	for(int i=m-1;i>=1;--i){
		if(b[i]-'a'==B.back().first)++B.back().second;
		else B.push_back(make_pair(b[i]-'a',1));
	}
	if(A.size()==1&&B.size()==1){
		puts("0");return 0;
	}
	if(A.size()<B.size())swap(A,B),flag=true,swap(n,m);
	else flag=false;
	if(A.size()-B.size()>1){
		if(A.back().first==B.back().first){
			if(B.size()==1){
				int len=(A.size()-B.size()+1)/4*2+1,tot=0;
				if(!B.empty())B.back().second+=A[A.size()-len].second;
				else B.push_back(A[A.size()-len]);
				for(int i=len-1;i>=1;--i)B.push_back(A[A.size()-i]);
				for(int i=1;i<=len;++i)tot+=A.back().second,A.pop_back();
				ans.push_back(make_pair(tot,0));
			}
			else{
				int len=(A.size()-B.size())/4*2+2,tot=0;
				pair<int,int> qwq=getB();
				if(!B.empty())B.back().second+=A[A.size()-len].second;
				else B.push_back(A[A.size()-len]);
				for(int i=len-1;i>=1;--i)B.push_back(A[A.size()-i]);
				for(int i=1;i<=len;++i)tot+=A.back().second,A.pop_back();
				if(A.empty())A.push_back(qwq);
				else A.back().second+=qwq.second;
				ans.push_back(make_pair(tot,qwq.second));
			}	
		}
		else{
			int len=(A.size()-B.size()+1)/4*2+1,tot=0;
			pair<int,int> qwq=getB();
			if(!B.empty())B.back().second+=A[A.size()-len].second;
			else B.push_back(A[A.size()-len]);
			for(int i=len-1;i>=1;--i)B.push_back(A[A.size()-i]);
			for(int i=1;i<=len;++i)tot+=A.back().second,A.pop_back();
			if(A.empty())A.push_back(qwq);
			else A.back().second+=qwq.second;
			ans.push_back(make_pair(tot,qwq.second));
		}
	}
	
	while(A.size()>1||B.size()>1){
		if(A.back().first==B.back().first){
			if(A.size()>B.size()){
				if(B.size()==1){
					ans.push_back(make_pair(A.back().second,0));
					B.back().second+=A.back().second;
					A.pop_back();
				}
				else{
					ans.push_back(make_pair(A.back().second+A[A.size()-2].second,B.back().second));
					pair<int,int> x,y,z;
					x=getA(),y=getA(),z=getB();
					B.back().second+=y.second;
					B.push_back(x);
					if(A.empty())A.push_back(z);
					else A.back().second+=z.second;
				}
			}
			else{
				if(A.size()==1){
					ans.push_back(make_pair(0,B.back().second));
					A.back().second+=B.back().second;
					B.pop_back();
				}
				else{
					ans.push_back(make_pair(A.back().second,B.back().second+B[B.size()-2].second));
					pair<int,int> x,y,z;
					x=getB(),y=getB(),z=getA();
					A.back().second+=y.second;
					A.push_back(x);
					if(B.empty())B.push_back(z);
					else B.back().second+=z.second;
				}
			}
		}
		else{
			ans.push_back(make_pair(A.back().second,B.back().second));
			swap(A.back(),B.back());
			if(A.size()>1)A[A.size()-2].second+=A.back().second,A.pop_back();
			if(B.size()>1)B[B.size()-2].second+=B.back().second,B.pop_back();
		}
	}
	printf("%d\n",(int)ans.size());
	for(auto x:ans){
		if(flag)printf("%d %d\n",x.second,x.first);
		else printf("%d %d\n",x.first,x.second);
	}
	return 0;
}