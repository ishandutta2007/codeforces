#include <iostream>
using namespace std;
#include<bits/stdc++.h>
int main() {
    int n;
    cin >>n;
    string str[n];
    for(int i=0;i<n;i++)cin>> str[i];
    int count[26];
    for(int i=0;i<26;i++)count[i]=0;
    for(int i=0;i<n;i++){
        count[str[i][0] - 'a']++;
    }
    int countans=0;
    for(int i=0;i<26;i++){
        if(count[i]==1 || count[i]==0);
        else if(count[i]%2==0){
            countans += count[i]/2 *(count[i]/2 - 1);
         }
        else {
            countans+= ((count[i]/2 * (count[i]/2 -1) /2)   +(count[i]/2 * (count[i]/2 +1) /2) );
        }
    }
    cout<< countans;
	// your code goes here
	return 0;
}