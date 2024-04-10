#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<ll,ll>
#define iii pair<ll,ii>
#define endl '\n'

int n,k;
map<string,int> m;

bool view[45];

bool am[55][55];

int can[1050000];
int prec[25];

int memo1[1050000];
int memo2[1050000];

int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	
	cin>>k>>n;
	
	int a;
	string s;
	
	int counter=0;
	while (k--){
		cin>>a;
		if (a==1){		
			memset(view,false,sizeof(view));
		}
		else{
			cin>>s;
			
			if (!m.count(s)) m[s]=counter++;
			
			int temp=m[s];
			
			for (int x=0;x<n;x++) if (view[x]) am[x][temp]=am[temp][x]=true;
			
			view[temp]=true;
		}
	}			
	
	memset(memo1,-128,sizeof(memo1));
	memset(memo2,-128,sizeof(memo2));
	
	int s1=n/2,s2=(n+1)/2;
	
		
	for (int x=0;x<s2;x++){
		for (int y=0;y<s1;y++) if (am[y][s1+x]){
			prec[x]|=(1<<y);
		}
	}
				
	memset(can,-1,sizeof(can));
	can[0]=1;
	
	for (int bm=0;bm<(1<<s2);bm++){
		if (can[bm]!=1) continue;
		
		for (int x=0;x<s2;x++){
			if (can[bm|(1<<x)]==-1){
				for (int y=0;y<s2;y++){
					if ((bm&(1<<y)) && am[s1+y][s1+x]){
						can[bm|(1<<x)]=0;
						break;
					}
				}
				if (can[bm|(1<<x)]!=0) can[bm|(1<<x)]=1;
			}
		}
		
		int mask=0;
		for (int x=0;x<s2;x++){
			if ((1<<x)&bm) mask|=prec[x];
		}
		memo1[mask]=max(memo1[mask],__builtin_popcount(bm));
		//cout<<"memo1 "<<mask<<" "<<__builtin_popcount(bm)<<endl;
	}
	
	memset(can,-1,sizeof(can));
	can[0]=1;
	
	for (int bm=0;bm<(1<<s1);bm++){
		if (can[bm]!=1) continue;
		
		for (int x=0;x<s1;x++){
			if (can[bm|(1<<x)]==-1){
				for (int y=0;y<s1;y++){
					if ((bm&(1<<y)) && am[y][x]){
						can[bm|(1<<x)]=0;
						break;
					}
				}
				if (can[bm|(1<<x)]!=0) can[bm|(1<<x)]=1;
			}
		}
		
		memo2[bm]=max(memo2[bm],__builtin_popcount(bm));
		//cout<<"memo2 "<<bm<<" "<<__builtin_popcount(bm)<<endl;
	}
	
	for (int x=0;x<(1<<s1);x++)
		for (int y=0;y<s1;y++)
			memo1[x|(1<<y)]=max(memo1[x|(1<<y)],memo1[x]);
			
			
	int ans=0;
	for (int x=0;x<(1<<s1);x++)
		ans=max(ans,memo1[x]+memo2[((1<<s1)-1)^x]);

	cout<<ans<<endl;
}