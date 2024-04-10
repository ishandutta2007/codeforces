#include<iostream>
#include<algorithm>
using namespace std;
int n,m;
int size=1;
int c[9000001][2];
int cnt[9000001];
int a[300001],p[300001];
void insert(int num){
	int ans=0,ptr=0;
	for(int i=30; i>=0 ;i--){
		int newi=((num&(1<<i))!=0);
		if(c[ptr][newi]==0){
			c[ptr][newi]=size;
			size++;
		}
		cnt[c[ptr][newi]]++;
		ptr=c[ptr][newi];
	}
}
int answer(int id){
	int ans=0,ptr=0;
	for(int i=30; i>=0 ;i--){
		int newi=(id&(1<<i))!=0;
		if(c[ptr][newi]!=0 && cnt[c[ptr][newi]]!=0){
			cnt[c[ptr][newi]]--;
			ptr=c[ptr][newi];
			ans=ans*2+newi;
		}
		else{
			newi=1-newi;
			cnt[c[ptr][newi]]--;
			ptr=c[ptr][newi];
			ans=ans*2+newi;
		}
	}
	cout << (ans^id) << ' ';
}
int main(){
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i=1; i<=n ;i++){
    	cin >> a[i];
	}
	for(int i=1; i<=n ;i++){
		cin >> p[i];
		insert(p[i]);
	}
	for(int i=1; i<=n ;i++){
		answer(a[i]);
	}
}