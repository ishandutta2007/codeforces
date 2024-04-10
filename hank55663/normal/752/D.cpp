#include<set>
#include<map>
#include<stdio.h>
#include<vector>
#include<string>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<stack>
#define Min(a,b,c) min((a),min((b),(c)))
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pb(x) push_back(x)
#define x first
#define y second
#define N 100005
#define sqrt(x) ((x)*(x))
using namespace std;
typedef long long ll;
int main(){
	int n,k;
	scanf("%d %d",&n,&k);
	map<string,vector<int> >m;
	for(int i=0;i<n;i++){
		string s;
		cin>>s;
		int a;
		scanf("%d",&a);
		m[s].pb(a);
	}
	long long int ans=0,mi=0,ma=0;
	for(map<string,vector<int> >::iterator it=m.begin();it!=m.end();it++)
	sort(it->y.begin(),it->y.end());
	for(map<string,vector<int> >::iterator it=m.begin();it!=m.end();it++)
	{
		string s=it->x;
		string s1=s;
		reverse(s.begin(),s.end());
		if(s1==s){
			while(!it->y.empty()){
				long long int a=it->y.back();
				it->y.pop_back();
				if(!it->y.empty())
				{
					long long int b=it->y.back();
					it->y.pop_back();
					if(a+b>=0){
						ans+=a+b;
						if(b<0)
						mi=min(b,mi);
					}
					else{
						if(a>0)
						ma=max(a,ma);
						break;
					}
				}
				else{
					if(a>0)
					ma=max(a,ma);
				}
			}
		}
		else{
			while(!it->y.empty()&&!m[s].empty()){
				if(it->y.back()+m[s].back()>0){
					ans+=it->y.back()+m[s].back();
					it->y.pop_back();
					m[s].pop_back();
				}
				else{
					break;
				}
			}
		}
	}
	printf("%I64d",max(ans-mi,ans+ma));
}
/*
1 2 3 4
10 11 12 13 14
20 21 22 23 24
30 31 32 33 34
40 41 42 43 44*/