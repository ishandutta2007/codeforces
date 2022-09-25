#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[8][8]={
	42,33,26,9,62,13,28,11,
	25,8,41,58,27,10,63,14,
	34,43,32,61,40,59,12,29,
	7,24,57,50,31,64,15,52,
	44,35,46,39,60,51,30,1,
	23,6,49,56,47,18,53,16,
	36,45,4,21,38,55,2,19,
	5,22,37,48,3,20,17,54
};
int n,c[64];
pair<int,int> p[64];
vector<pair<int,int> > ans;
void Solve(){
	cin>>n;
	for(int i=0;i<8;++i)
		for(int j=0;j<8;++j)
			p[--a[i][j]]=make_pair(i,j);
	for(int i=1;i<=n;++i){
		string s;
		cin>>s;
		int x=s[0]-'a';
		int y=s[1]-'1';
		c[a[x][y]]=1;
	}
	int cnt=0;
	for(int j=0;j<8;++j){
		for(int i=0;i<8;++i){
			if(c[a[i][j]]){
				int tx=cnt%8,ty=cnt/8;
				if(i==tx&&j==ty){++cnt;continue;}
				int las=a[tx][ty];
				if((a[tx][ty]-a[i][j]+64)%64<32){
					for(int k=a[tx][ty];;k=(k+63)%64){
						if(c[k]){
							for(int z=k;z^las;z=(z+1)%64){
								swap(c[z],c[(z+1)%64]);
								ans.emplace_back(z,(z+1)%64);
							}
							las=k;
						}
						if(k==a[i][j])break;
					}
				}
				else{
					for(int k=a[tx][ty];;k=(k+1)%64){
						if(c[k]){
							for(int z=k;z^las;z=(z+63)%64){
								swap(c[z],c[(z+63)%64]);
								ans.emplace_back(z,(z+63)%64);
							}
							las=k;
						}
						if(k==a[i][j])break;
					}					
				}
				++cnt;	
			}		
		}
	}
	printf("%d\n",(int)ans.size());
	for(auto [i,j]:ans){
		putchar(p[i].first+'a'),putchar(p[i].second+'1'),putchar('-'),putchar(p[j].first+'a'),putchar(p[j].second+'1'),putchar('\n');
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T=1;
	while(T--)Solve();
	return 0;
}