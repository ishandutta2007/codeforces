#include<bits/stdc++.h>
using namespace std;
int main (){
	
	ios::sync_with_stdio(false);
	map<int,int> m;
	int x;
	cin>>x;
	int now[x];
	char c;
		int ok[26];
	for(int i=0;i<26;i++){
		ok[i]=1;
	}
	vector<int> star;
	for(int i=0;i<x;i++){
		cin>>c;
		if(c=='*'){
			now[i]=-1;
			star.push_back(i);
		}else{
			now[i]=(int)(c-97);
			m[now[i]]++;
			ok[now[i]]=0;
		}
		
		
	}

	int y;
	cin>>y;
	for(int i=0;i<y;i++){
		string str;
		cin>>str;
		int check=1;
		int lol[26]={0};
		for(int j=0;j<x;j++){
			if(now[j]!=-1){
			//	ok[(int)(str[j]-97)]=0;
				lol[(int)(str[j]-97)]++;
			}
			
			}
			
		for(int k=0;k<x;k++){
				if(now[k]==-1&&lol[str[k]-97]!=0){
					check=0;
				}else if(now[k]!=-1&&(int)(str[k]-97)!=now[k]){
					check=0;
				}
			}
			if(check==1){
				for(int j=0;j<x;j++){
			if(now[j]!=-1){
				ok[(int)(str[j]-97)]=0;
			//	lol[(int)(str[j]-97)]++;
			}	int save[26]={0};
		for(int j=0;j<star.size();j++){
			save[(int)(str[star[j]]-97)]=1;
		}
		for(int j=0;j<26;j++){
			ok[j]=ok[j]&save[j];
		}
			}
			
			}
	
	}
	int o=0;
	for(int j=0;j<26;j++){
		if(ok[j]==1){
			o++;
		}
	}
	cout<<o<<endl;
}