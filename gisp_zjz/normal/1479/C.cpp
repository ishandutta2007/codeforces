#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef pair<int,int>pi;
typedef long long ll;
const int maxn=1e6+100;
const int M=998244353;
const int N=20;
struct edge{
	int x,y,c;
};
vector<edge> ans;
int L,R;
int main(){
	int n=N+2;
    for (int i=0;i<N;i++){
		for (int j=i+1;j<N;j++)
			ans.pb((edge){N+1-j,N+1-i,1<<i});
		ans.pb((edge){N+1-i,n,1});
    }
    cin >> L >> R;
    int dif=R-L;
    ans.pb((edge){1,n,L});
    for (int i=N-1;i>=0;i--){
		if (dif&(1<<i)){
            ans.pb((edge){1,N+1-i,L});
            L+=1<<i;
		}
    }
    puts("YES");
    printf("%d %d\n",n,(int)ans.size());
    for (auto e:ans) printf("%d %d %d\n",e.x,e.y,e.c);
    return 0;
}