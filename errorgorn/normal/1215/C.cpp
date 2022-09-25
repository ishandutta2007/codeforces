#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
using namespace std;
int n;
string s1,s2;
vector<int> ab;
vector<int> ba;
int main(){
    scanf("%d",&n);
    cin>>s1>>s2;
    for (int x=0;x<n;x++){
        if (s1[x]=='a' && s2[x]=='b') ab.push_back(x+1);
        if (s1[x]=='b' && s2[x]=='a') ba.push_back(x+1);
    }
    if ((ab.size()+ba.size())%2==1){
        printf("-1\n");
        return 0;
    }
    printf("%d\n",(ab.size()+ba.size())/2+(ab.size()%2==1));
    while (ab.size()>=2){
        printf("%d ",ab.back());
        ab.pop_back();
        printf("%d\n",ab.back());
        ab.pop_back();
    }
    while (ba.size()>=2){
        printf("%d ",ba.back());
        ba.pop_back();
        printf("%d\n",ba.back());
        ba.pop_back();
    }
    if (ab.size()==1){
        printf("%d %d\n%d ",ab.back(),ab.back(),ab.back());
        printf("%d\n",ba.back());
    }
}