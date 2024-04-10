#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main () {
    int q; cin>>q; for(int l=1; l<=q; l++) {
        int n; cin>>n; string s1, s2; cin>>s1>>s2;
        int a[n][2]; for(int i=0; i<n; i++) a[i][0]=s1[i]-'0'; for(int i=0; i<n; i++) a[i][1]=s2[i]-'0';
        int currx=0, curry=0, arr=1; bool visited[n][2]={0};
        while(1) {
            if(currx==n&&curry==1) {
                cout<<"YES"<<endl; break;
            }
            else if(currx<0||currx>=n||curry<0||curry>1) {
                cout<<"NO"<<endl; break;
            }
            else if(visited[currx][curry]) {
                cout<<"NO"<<endl; break;
            }
            else visited[currx][curry]=1;
            if(a[currx][curry]==1||a[currx][curry]==2) {
                if(arr==1) {
                    currx++; arr=1;
                }
                else if (arr==2) {
                    curry++; arr=2;
                }
                else if (arr==3){
                    currx--; arr=3;
                }
                else {
                    curry--; arr=4;
                }
            }
            else {
                if(arr==1||arr==3) {
                    if(curry==1) {curry--; arr=4;}
                    else {curry++; arr=2;}
                }
                else {
                    currx++; arr=1;
                }
            }
        }
    }
}