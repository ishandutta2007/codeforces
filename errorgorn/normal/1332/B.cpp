#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<ll,ll>
#define iii pair<ll,ii>
#define endl '\n'

const int p[]={2,3,5,7,11,13,17,19,23,29,31};

int n;
int arr[1005];
int ans[1005];

int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	
	int TC;
	cin>>TC;
	while (TC--){
		cin>>n;
		int t;
		for (int x=0;x<n;x++){
			cin>>t;
			for (int y=0;;y++){
				if (t%p[y]==0){
					arr[x]=y;
					break;
				}
			}
		}
		
		
		int index=0;
		map<int,int> m;
		
		for (int x=0;x<n;x++){
			if (!m.count(arr[x])){
				m[arr[x]]=++index;
			}
			
			ans[x]=m[arr[x]];
		}
		
		cout<<index<<endl;
		for (int x=0;x<n;x++) cout<<ans[x]<<" ";
		cout<<endl;
		
	}
}