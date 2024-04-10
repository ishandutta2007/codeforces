#include<bits/stdc++.h>
using namespace std;
int main(){
	vector< pair<int,int> > v;
	int arr[8][8];
	int vis[8][8];
	int n;
	cin>>n;
	n++;
	int tmp=n;
	if(n<=51){
		for(int i=0;i<7;i++){
			if(n==0)
				break;
			for(int j=0;j<7;j++){
				// if i%2==0 j inc
				// i%2!=0 J DEC 6-J
				int curj;
				if(i%2==0)
					curj=j;
				else
					curj=6-j;
				v.push_back(make_pair(i,curj));
				n--;
				if(n==2){
					v.push_back(make_pair(7,curj));
					v.push_back(make_pair(7,7));
					n=0;
					break;
				}

			}
		}
	}
	else if(n<=57){
		for(int i=0;i<=7;i++){
			if(n==0)
				break;
			for(int j=0;j<=7;j++){
				// if i%2==0 j inc
				// i%2!=0 J DEC 6-J
				int curj;
				if(i%2==0)
					curj=j;
				else
					curj=7-j;
				v.push_back(make_pair(i,curj));
				n--;
				if(n==2){
					v.push_back(make_pair(7,curj));
					v.push_back(make_pair(7,7));
					n=0;
					break;
				}

			}
		}
		
		
	}
	else{
		for(int i=0;i<=7;i++){
			if(n==0)
				break;
			for(int j=0;j<=7;j++){
				// if i%2==0 j inc
				// i%2!=0 J DEC 6-J
				if(i==6&&j==6){
					v.push_back(make_pair(i,7));
					n--;
					v.push_back(make_pair(i,6));
					n--;
					v.push_back(make_pair(i+1,6));
					n--;
					j=0;
					while(n>0){
						if(n==1){
							v.push_back(make_pair(7,7));
							n--;
							break;
						}
						v.push_back(make_pair(7,j));
						j++;
						n--;
					}
				}
				if(n==0)
					break;
				int curj;
				if(i%2==0)
					curj=j;
				else
					curj=7-j;
				v.push_back(make_pair(i,curj));
				n--;
				if(n==2){
					v.push_back(make_pair(7,curj));
					v.push_back(make_pair(7,7));
					n=0;
					break;
				}

			}
		}
		
	}
	//cout<<v.size()-1<<endl;
	cout<<"a1 ";
	for(int i=1;i<v.size();i++){
		int row=v[i].first;
		int col=v[i].second;
		char c='a'+col;
		cout<<c<<1+row<<" ";
	}
	//cout<<endl;
		
	//else if(n<=56)
}