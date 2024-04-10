#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
bool solve(){
	
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	string s;cin >> s;
	int n=s.size();s='?'+s;
	if(n%2==1){
		for(int i=1; i<=(n+1)/2 ;i++) cout << '4';
		for(int i=1; i<=(n+1)/2 ;i++) cout << '7';
		return 0;
	}
	string f;
	for(int i=1; i<=n/2 ;i++) f+='7';
	for(int i=1; i<=n/2 ;i++) f+='4';
	f='?'+f;
	if(s>f){
		for(int i=1; i<=(n+2)/2 ;i++) cout << '4';
		for(int i=1; i<=(n+2)/2 ;i++) cout << '7';
		return 0;
	}
	int ptr=0;
	int c4=0,c7=0;
	for(int i=1; i<=n ;i++){
		if(s[i]=='4' || s[i]=='7'){
			ptr++;
			if(s[i]=='4') c4++;
			else c7++;
		}
		else break;
	}
	//cout << ptr << ' ' << c4 << ' ' << c7 << endl;
	if(c4<=n/2 && c7<=n/2){
		if(ptr==n){
			for(int i=1; i<=n ;i++) cout << s[i];
			return 0;
		}
		if(s[ptr+1]>'7' || s[ptr+1]>'4' && c7==n/2){
			while(s[ptr]=='7'){
				c7--;ptr--;
			}
			c4--;ptr--;
			for(int i=1; i<=ptr ;i++) cout << s[i];
			cout << 7;c7++;
			for(int i=c4+1; i<=n/2 ;i++) cout << 4;
			for(int i=c7+1; i<=n/2 ;i++) cout << 7;
		}
		else{
			for(int i=1; i<=ptr ;i++) cout << s[i];
			if(s[ptr+1]>'4') cout << 7,c7++,ptr++;
			for(int i=c4+1; i<=n/2 ;i++) cout << 4;
			for(int i=c7+1; i<=n/2 ;i++) cout << 7;
		}
	}
	else{
		while(c4>n/2 || c7>n/2){
			if(s[ptr]=='4') c4--;
			else c7--;
			ptr--;
		}
		if(c4==n/2){
			for(int i=1; i<=ptr ;i++) cout << s[i];
			for(int i=ptr+1; i<=n ;i++) cout << '7';
			return 0;
		}
		while(c7>=n/2){
			if(s[ptr]=='4') c4--;
			else c7--;
			ptr--;
		}
		while(s[ptr]=='7'){
			c7--;ptr--;
		}
		c4--;ptr--;
		for(int i=1; i<=ptr ;i++) cout << s[i];
		cout << 7;c7++;
		for(int i=c4+1; i<=n/2 ;i++) cout << 4;
		for(int i=c7+1; i<=n/2 ;i++) cout << 7;
		return 0;
	}
}