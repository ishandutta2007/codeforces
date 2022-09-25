#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n1,n2,n3;
vector<vector<vector<int> > > a;
vector<vector<vector<int> > > TX0,TX1,TY0,TY1,TZ0,TZ1;
vector<vector<int> > X0,X1,Y0,Y1,Z0,Z1;
void Output(){
	for(int i=0;i<n1;++i){
		for(int j=0;j<n2;++j){
			for(int k=0;k<n3;++k){
				cout<<max(a[i][j][k],0)<<' ';
				//cout<<a[i][j][k]<<' ';
			}
			cout<<'\n';
		}
		cout<<'\n';
	}	
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n1>>n2>>n3;
	a.resize(n1);
	for(int i=0;i<n1;++i){
		a[i].resize(n2);
		for(int j=0;j<n2;++j){
			a[i][j]=vector<int>(n3,-1);
		}
	}
	X0.resize(n2);
	X1.resize(n2);
	TX0.resize(n2);
	TX1.resize(n2);
	for(int i=0;i<n2;++i){
		X0[i].resize(n3);
		X1[i].resize(n3);
		TX0[i].resize(n3);
		TX1[i].resize(n3);
		for(int j=0;j<n3;++j){
			cin>>X0[i][j];
			for(int k=0;k<n1;++k){
				TX1[i][j].push_back(k);	
			}
			for(int k=n1-1;k>=0;--k){
				TX0[i][j].push_back(k);	
			}
		}
	}
	for(int i=0;i<n2;++i){
		for(int j=0;j<n3;++j){
			cin>>X1[i][j];	
		}	
	}
	Y0.resize(n1);
	Y1.resize(n1);
	TY0.resize(n1);
	TY1.resize(n1);
	for(int i=0;i<n1;++i){
		Y0[i].resize(n3);
		Y1[i].resize(n3);
		TY0[i].resize(n3);
		TY1[i].resize(n3);
		for(int j=0;j<n3;++j){
			cin>>Y0[i][j];
			for(int k=0;k<n2;++k){
				TY1[i][j].push_back(k);	
			}
			for(int k=n2-1;k>=0;--k){
				TY0[i][j].push_back(k);	
			}
		}
	}
	for(int i=0;i<n1;++i){
		for(int j=0;j<n3;++j){
			cin>>Y1[i][j];
		}
	}
	Z0.resize(n1);
	Z1.resize(n1);
	TZ0.resize(n1);
	TZ1.resize(n1);
	for(int i=0;i<n1;++i){
		Z0[i].resize(n2);
		Z1[i].resize(n2);
		TZ0[i].resize(n2);
		TZ1[i].resize(n2);
		for(int j=0;j<n2;++j){
			cin>>Z0[i][j];
			for(int k=0;k<n3;++k){
				TZ1[i][j].push_back(k);	
			}
			for(int k=n3-1;k>=0;--k){
				TZ0[i][j].push_back(k);	
			}
		}
	}
	for(int i=0;i<n1;++i){
		for(int j=0;j<n2;++j){
			cin>>Z1[i][j];
		}
	}
	while(true){
		bool ok=false;
		for(int j=0;j<n2;++j){
			for(int k=0;k<n3;++k){
				if(!X0[j][k]){
					while(!TX0[j][k].empty()){
						int i=TX0[j][k].back();
						TX0[j][k].pop_back();
						a[i][j][k]=0;	
						ok=true;
					}	
				}
				else{
					while(!TX0[j][k].empty()&&~a[TX0[j][k].back()][j][k]&&a[TX0[j][k].back()][j][k]^X0[j][k]){
						int i=TX0[j][k].back();
						TX0[j][k].pop_back();
						a[i][j][k]=0;	
						ok=true;
					}
					if(TX0[j][k].empty()){
						cout<<-1<<'\n';
						return 0;
					}
					a[TX0[j][k].back()][j][k]=X0[j][k];
				}	
				if(!X1[j][k]){
					while(!TX1[j][k].empty()){
						int i=TX1[j][k].back();
						TX1[j][k].pop_back();
						a[i][j][k]=0;	
						ok=true;
					}	
				}
				else{
					while(!TX1[j][k].empty()&&~a[TX1[j][k].back()][j][k]&&a[TX1[j][k].back()][j][k]^X1[j][k]){
						int i=TX1[j][k].back();
						TX1[j][k].pop_back();
						a[i][j][k]=0;	
						ok=true;
					}
					if(TX1[j][k].empty()){
						cout<<-1<<'\n';
						return 0;
					}
					a[TX1[j][k].back()][j][k]=X1[j][k];
				}	
			}	
		}
		for(int i=0;i<n1;++i){
			for(int k=0;k<n3;++k){
				if(!Y0[i][k]){
					while(!TY0[i][k].empty()){
						int j=TY0[i][k].back();
						TY0[i][k].pop_back();
						a[i][j][k]=0;	
						ok=true;
					}	
				}
				else{
					while(!TY0[i][k].empty()&&~a[i][TY0[i][k].back()][k]&&a[i][TY0[i][k].back()][k]^Y0[i][k]){
						int j=TY0[i][k].back();
						TY0[i][k].pop_back();
						a[i][j][k]=0;	
						ok=true;
					}
					if(TY0[i][k].empty()){
						cout<<-1<<'\n';
						return 0;
					}
					a[i][TY0[i][k].back()][k]=Y0[i][k];
				}	
				if(!Y1[i][k]){
					while(!TY1[i][k].empty()){
						int j=TY1[i][k].back();
						TY1[i][k].pop_back();
						a[i][j][k]=0;	
						ok=true;
					}	
				}
				else{
					while(!TY1[i][k].empty()&&~a[i][TY1[i][k].back()][k]&&a[i][TY1[i][k].back()][k]^Y1[i][k]){
						int j=TY1[i][k].back();
						TY1[i][k].pop_back();
						a[i][j][k]=0;	
						ok=true;
					}
					if(TY1[i][k].empty()){
						cout<<-1<<'\n';
						return 0;
					}
					a[i][TY1[i][k].back()][k]=Y1[i][k];
				}	
			}	
		}
		for(int i=0;i<n1;++i){
			for(int j=0;j<n2;++j){
				if(!Z0[i][j]){
					while(!TZ0[i][j].empty()){
						int k=TZ0[i][j].back();
						TZ0[i][j].pop_back();
						a[i][j][k]=0;	
						ok=true;
					}	
				}
				else{
					while(!TZ0[i][j].empty()&&~a[i][j][TZ0[i][j].back()]&&a[i][j][TZ0[i][j].back()]^Z0[i][j]){
						int k=TZ0[i][j].back();
						TZ0[i][j].pop_back();
						a[i][j][k]=0;	
						ok=true;
					}
					if(TZ0[i][j].empty()){
						cout<<-1<<'\n';
						return 0;
					}
					a[i][j][TZ0[i][j].back()]=Z0[i][j];
				}	
				if(!Z1[i][j]){
					while(!TZ1[i][j].empty()){
						int k=TZ1[i][j].back();
						TZ1[i][j].pop_back();
						a[i][j][k]=0;	
						ok=true;
					}	
				}
				else{
					while(!TZ1[i][j].empty()&&~a[i][j][TZ1[i][j].back()]&&a[i][j][TZ1[i][j].back()]^Z1[i][j]){
						int k=TZ1[i][j].back();
						TZ1[i][j].pop_back();
						a[i][j][k]=0;	
						ok=true;
					}
					if(TZ1[i][j].empty()){
						cout<<-1<<'\n';
						return 0;
					}
					a[i][j][TZ1[i][j].back()]=Z1[i][j];
				}	
			}	
		}
		if(!ok)break;
	}
	Output();
	return 0;
}