#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef long double db;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<db,db> pdb;
typedef tuple<int,int,int,int> TP;
typedef vector<vector<ll>> mat;
const int N=2005;
const ll mod=1e9+7;
int a[4][4]={
	{8,9,1,13},
	{3,12,7,5},
	{0,2,4,11},
	{6,10,15,14}
};
int n,cnt,res[N][N];
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
	cin>>n;
	for(int i=0;i<n;i+=4){
		for(int j=0;j<n;j+=4){
			for(int k=i;k<i+4;k++){
				for(int l=j;l<j+4;l++){
					res[k][l]=a[k-i][l-j]+cnt;
				}
			}
			cnt+=16;
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++) cout<<res[i][j]<<" ";
		cout<<"\n";
	}
    return 0;
}