#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long LL;
#define PB push_back
#define ST first
#define ND second

int n;
int cnt[26],minodd,maxodd,mineven,maxeven;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    while(n--) {
		minodd =mineven= 25;
		maxodd =maxeven=0;
		for(int i=0; i<26;i++) cnt[i]=0;
		string s;
		cin>>s;
		for(auto c:s) {
			if(((int)c)%2==1) {
				maxeven = max(maxeven,(int)c-'a');
				mineven = min(mineven,(int)c-'a');
			}
			else {
				maxodd = max(maxodd,(int)c-'a');
				minodd = min(minodd,(int)c-'a');
			}
			cnt[c-'a']++;
		}
		//cout<<minodd<<" "<<maxodd<<" "<<mineven<<" "<<maxeven<<"\n";
		if(abs(minodd-maxeven)!=1) {
			for(int i=0; i<26;i+=2) {
				if(i!=maxeven) {
				while(cnt[i]--) {
					cout<<(char)(i+'a');
				}
			}
			}
			while(cnt[maxeven]--) {
				cout<<(char)(maxeven+'a');
			}
			while(cnt[minodd]--) {
				cout<<(char)(minodd+'a');
			}
			for(int i=1; i<26;i+=2) {
				if(cnt[i]<0) continue;
				while(cnt[i]--) {
					cout<<(char)(i+'a');
				}
			}
		}
		else if(abs(mineven-maxodd)!=1) {
			for(int i=0; i<26;i+=2) {
				if(i!=mineven) {
				while(cnt[i]--) {
					cout<<(char)(i+'a');
				}
			}
			}
			while(cnt[mineven]--) {
				cout<<(char)(mineven+'a');
			}
			while(cnt[maxodd]--) {
				cout<<(char)(maxodd+'a');
			}
			for(int i=1; i<26;i+=2) {
				if(cnt[i]<0) continue;
				while(cnt[i]--) {
					cout<<(char)(i+'a');
				}
			}
		}
		else {
			cout<<"No answer";
		}
		cout<<"\n";
	}
}