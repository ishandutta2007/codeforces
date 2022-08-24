#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	string n;
	cin >> n;
	int j;
	for(int i=0; i<n.size()-1 ;i++){
		j=i;
		while(i<n.size()-1 && n[i]==n[i+1]){
			i++;
		}
		for(j++; j<=i ;j+=2){
			for(char k='a'; k<'d' ;k++){
				if(n[i]!=k && (i+1==n.size() || n[i+1]!=k)){
					n[j]=k;
					break;
				}
			}
		}
	}
	cout << n << endl;
}