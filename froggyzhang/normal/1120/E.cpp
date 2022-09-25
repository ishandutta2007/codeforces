#include<bits/stdc++.h>
using namespace std;
#define N 1010
const int B=2000;
typedef long long ll;
typedef pair<int,int> pii;
int vis[N][N<<2],A;
pair<pii,int> pre[N][N<<2];
queue<pii> q;
int main(){
	cin>>A;
	q.push(make_pair(0,B));
	while(!q.empty()){
		auto [x,y]=q.front();
		q.pop();
		for(int c=0;c<10;++c){
			if(!c&&!vis[x][y])continue;
			int i=(x+c*A)/10;
			int j=(y+c-(x+c*A)%10*A);
			if(j<0||j>2*B||vis[i][j])continue;
			vis[i][j]=1;
			q.push(make_pair(i,j));
			pre[i][j]=make_pair(make_pair(x,y),c);		
		}
	}
	if(!vis[0][B]){
		cout<<-1<<'\n';
		return 0;
	}
	int x=0,y=B,ze=0;
	while("zykmd"){
		auto [t,c]=pre[x][y];
		if(c||ze)cout<<c;
		ze|=c;
		x=t.first,y=t.second;
		if(!x&&y==B)break;
	}
	return 0;
}