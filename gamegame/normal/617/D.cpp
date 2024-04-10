#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	int a[4],b[4];
	for(int i=1; i<=3 ;i++){
		cin >> a[i] >> b[i];
	}
	if(a[1]==a[2] && a[2]==a[3] || b[1]==b[2] && b[2]==b[3]){
		cout << 1 << endl;
		return 0;
	}
	int c[3],ptr;
	for(int i=1; i<=3 ;i++){
		ptr=1;
		for(int j=1; j<=3 ;j++){
			if(i!=j){
				c[ptr]=j;
				ptr++;
			}
		}
		if(a[i]==a[c[1]]){
			if(b[c[2]]>b[i]){
				if(b[c[2]]>=b[c[1]]){
					cout << 2 << endl;
					return 0;
				}
			}
			else if(b[c[2]]<b[i]){
				if(b[c[2]]<=b[c[1]]){
					cout << 2 << endl;
					return 0;
				}
			}
			else{
				cout << 2 << endl;
				return 0;
			}
		}
		else if(a[i]==a[c[2]]){
			swap(c[1],c[2]);
			if(b[c[2]]>b[i]){
				if(b[c[2]]>=b[c[1]]){
					cout << 2 << endl;
					return 0;
				}
			}
			else if(b[c[2]]<b[i]){
				if(b[c[2]]<=b[c[1]]){
					cout << 2 << endl;
					return 0;
				}
			}
			else{
				cout << 2 << endl;
				return 0;
			}
		}
		else if(b[i]==b[c[1]]){
			swap(a,b);
			if(b[c[2]]>b[i]){
				if(b[c[2]]>=b[c[1]]){
					cout << 2 << endl;
					return 0;
				}
			}
			else if(b[c[2]]<b[i]){
				if(b[c[2]]<=b[c[1]]){
					cout << 2 << endl;
					return 0;
				}
			}
			else{
				cout << 2 << endl;
				return 0;
			}
			swap(a,b);
		}
		else if(b[i]==b[c[2]]){
			swap(a,b);
			swap(c[1],c[2]);
			if(b[c[2]]>b[i]){
				if(b[c[2]]>=b[c[1]]){
					cout << 2 << endl;
					return 0;
				}
			}
			else if(b[c[2]]<b[i]){
				if(b[c[2]]<=b[c[1]]){
					cout << 2 << endl;
					return 0;
				}
			}
			else{
				cout << 2 << endl;
				return 0;
			}
			swap(a,b);
		}
		else{
			continue;
		}
	}
	cout << 3 << endl;
}