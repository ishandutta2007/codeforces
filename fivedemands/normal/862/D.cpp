#include<iostream>
#include<vector>
using namespace std;
int n;
string ask;
int verd;
int pos1,pos2;
int cnt=1;
void find(int l,int r){
	if(l==r){
		if(pos1==0) pos1=l;
		else if(pos2==0) pos2=l;
		return;
	}
	int mid=(l+r)/2;
	int num1,num2;
	num1=verd;
	for(int i=l; i<=mid ;i++){
		ask[i]='1';
	}
	cout << '?' << ask << endl;
	cnt++;
	if(cnt>15) while(true);
	for(int i=l; i<=mid ;i++){
		ask[i]='0';
	}
	cin >> num2;
	if(num1-num2==mid-l+1){
		pos2=l;
		find(mid+1,r);
	}
	else if(num2-num1==mid-l+1){
		pos1=l;
		find(mid+1,r);
	}
	else find(l,mid);
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	ask+=' ';
	for(int i=0; i<n ;i++){
		ask+='0';
	}
	cout << '?' << ask << endl;
	cin >> verd;
	find(1,n);
	cout << "! " << pos1 << ' ' << pos2 << endl;
}