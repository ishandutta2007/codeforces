#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int> spread[3001];
vector<pair<int,int> > pin[3001];
vector<pair<int,int> > pout[3001];
int sp[3001][3001];
void putin(){
	memset(sp,0x3f3f3f3f,sizeof(sp));
	scanf("%d %d",&n,&m);
	while(m--){
		int A,B;
		scanf("%d %d",&A,&B);
		spread[A].push_back(B);
	}	
}
void Spread(){
	for(int i=1;i<=n;i++){//From point i
		sp[i][i]=0;
		queue<int> q;
		q.push(i);
		while(!q.empty()){
			int point=q.front();
			q.pop();
			vector<int>::iterator ite=spread[point].begin();
			for(ite;ite!=spread[point].end();ite++){
				if(sp[i][*ite]==0x3f3f3f3f){
					sp[i][*ite]=sp[i][point]+1;
					q.push(*ite);
				}
			}
		}	
	}
}
bool cmp(pair<int,int> a,pair<int,int> b){return a.first<b.first;}
void saveDATA(){
	for(int i=1;i<=n;i++){//From point i
		for(int j=1;j<=n;j++){//i>>j  out
			if(i==j) continue;
			if(sp[i][j]!=0x3f3f3f3f){
				pout[i].push_back(make_pair(sp[i][j],j));
			}
			if(pout[i].size()>3){
				sort(pout[i].begin(),pout[i].end(),cmp);
				pout[i].erase(pout[i].begin());
			}
		}
		for(int j=1;j<=n;j++){//i<<j  in
			if(i==j) continue;
			if(sp[j][i]!=0x3f3f3f3f){
//				cout<<sp[j][i]<<" "<<j<<endl;
				pin[i].push_back(make_pair(sp[j][i],j));
			}
			if(pin[i].size()>3){
				sort(pin[i].begin(),pin[i].end(),cmp);
				pin[i].erase(pin[i].begin());
//				cout<<pin[i].size()<<endl;
			}
		}
	}
}
int bb;
int cc;
int aa;
int dd;
int finalaa;
int finalbb;
int finalcc;
int finaldd;
int finalrec=-0x3f3f3f3f;
void update(){
//	cout<<aa<<" "<<bb<<" "<<cc<<" "<<dd<<" "<<endl;
	if(aa==bb||aa==cc||aa==dd||bb==cc||bb==dd||cc==dd) return;
	if(aa>3000||bb>3000||cc>3000||dd>3000) return;
	int tmprec=sp[aa][bb]+sp[bb][cc]+sp[cc][dd];
	if(tmprec>finalrec) {
		finalrec=tmprec;
		finalaa=aa;
		finalbb=bb;
		finalcc=cc;
		finaldd=dd;
	}
}
void Try(){
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			if(sp[i][j]!=0x3f3f3f3f){//aa>bb>cc>dd
				cc=j;
				bb=i;
				for(vector<pair<int,int> >::iterator ite1=pin[bb].begin();ite1!=pin[bb].end();ite1++){
					for(vector<pair<int,int> >::iterator ite2=pout[cc].begin();ite2!=pout[cc].end();ite2++){
						aa=(*ite1).second;
						dd=(*ite2).second;
//						cout<<aa<<" "<<dd<<endl;
						update();
					}
				}
			}
		}
}
int main(){
	putin();
	Spread();
	saveDATA();
	Try();
	printf("%d %d %d %d",finalaa,finalbb,finalcc,finaldd);
	return 0;
}