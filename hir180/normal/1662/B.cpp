#include <bits/stdc++.h>
#define SIZE 1005
#define ALP 30
using namespace std;
typedef pair <int,int> P;

int cnt[ALP][3];
char str[SIZE];
vector <int> cd[3];
vector <int> zan[3];
int main(){
	int mn=SIZE;
	for(int i=0;i<3;i++){
		scanf("%s",&str);
		int n=strlen(str);
		mn=min(mn,n);
		for(int j=0;j<n;j++){
			cnt[str[j]-'A'][i]++;
		}
	}
	for(int i=0;i<ALP;i++){
		while(mn>0){
			vector <P> vc;
			for(int j=0;j<3;j++) vc.push_back(P(cnt[i][j],j));
			sort(vc.begin(),vc.end(),greater <P>());
			if(vc[1].first==0) break;
			mn--;
			cd[vc[2].second].push_back(i);
			cnt[i][vc[0].second]--;
			cnt[i][vc[1].second]--;
		}
	}
	vector <string> ans;
	for(int i=0;i<3;i++){
		int pos=0;
		for(int j=0;j<ALP;j++){
			while(pos<cd[i].size()&&cnt[j][i]>0){
				string S="";
				char c='A'+cd[i][pos++];
				S+=c;
				c='A'+j;
				S+=c;
				ans.push_back(S);
				cnt[j][i]--;
			}
			while(cnt[j][i]>0){
				cnt[j][i]--;
				zan[i].push_back(j);
			}
		}
		while(pos<cd[i].size()){
			string S="";
			S+='A'+cd[i][pos++];
			S+='A';
			ans.push_back(S);
		}
	}
	while(1){
		vector <P> vc;
		for(int i=0;i<3;i++) vc.push_back(P(zan[i].size(),i));
		sort(vc.begin(),vc.end(),greater <P>());
		if(vc[0].first==0) break;
		string S="";
		int v=vc[0].second;
		char c='A'+zan[v][zan[v].size()-1];
		zan[v].pop_back();
		S+=c;
		v=vc[1].second;
		if(zan[v].size()>0){
			c='A'+zan[v][zan[v].size()-1];
			zan[v].pop_back();
			S+=c;
		} else{
			S+="A";
		}
		ans.push_back(S);
	}
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();i++) printf("%s\n",ans[i].c_str());
}