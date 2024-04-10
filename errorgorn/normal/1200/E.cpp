#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;
int n;
string base,add;
int b[1000005];
void kmpPreprocess(){
    int i=0,j=-1;
    b[0]=-1;
    while (i<add.size()){
        while (j>=0 && add[i]!=add[j]) j=b[j];
        i++;
        j++;
        b[i]=j;
    }
}
int main(){
    //freopen("input.txt","r",stdin);
    cin>>n;
    cin>>base;
    int i,j; ///iterators for base and add respectively
    while (--n){
        cin>>add;
        kmpPreprocess();
        i=max( 0, (int)base.size()-(int)add.size() );
        j=0;
        while (i<base.size()){
            while (j>=0 && base[i]!=add[j]) j=b[j];
            i++;
            j++;
        }
        base.insert(base.size(),add,j,-1);
    }
    cout<<base;
}