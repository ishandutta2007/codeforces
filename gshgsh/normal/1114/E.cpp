#include<algorithm>
#include<iostream>
#include<vector>
#include<random>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
int cnt;bool ask(int x){cout<<"> "<<x<<endl;cnt++;int y;cin>>y;return y;}
int main()
{
	int N;cin>>N;int l=0,r=1000000000,y=r;while(l<=r){int mid=l+r>>1;if(ask(mid))y=mid+1,l=mid+1;else r=mid-1;}
	vector<int>v{y};mt19937 rnd(0);while(cnt<60){int x=rnd()%N+1;cout<<"? "<<x<<endl;cnt++;int y;cin>>y;v.push_back(y);}
	sort(v.begin(),v.end());v.erase(unique(v.begin(),v.end()),v.end());vector<int>d;for(auto i:v)for(auto j:v)if(i!=j)d.push_back(abs(i-j));
	int x=d[0];for(auto i:d)x=__gcd(x,i);cout<<"! "<<y-x*(N-1)<<' '<<x<<endl;return 0;
}