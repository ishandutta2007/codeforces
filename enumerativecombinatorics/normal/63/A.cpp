#include<stdio.h>
#include<string>
#include<algorithm>
#include<iostream>
using namespace std;
pair<int,string> name[100];
char val[128];
char q[128];
int main(){
    int a;
    scanf("%d",&a);
    for(int i=0;i<a;i++){
        string q;
        cin>>q;
        scanf("%s",val);
        switch(val[0]){
            case 'c': 
                if(val[1]=='a')name[i]=make_pair(3000+i,q);
                else name[i]=make_pair(1000+i,q);
                break;
            case 'w': name[i]=make_pair(1000+i,q);break;
            case 'r': name[i]=make_pair(i,q);break;
            case 'm': name[i]=make_pair(2000+i,q);break;
        }
    }
    std::sort(name,name+a);
    for(int i=0;i<a;i++)printf("%s\n",name[i].second.c_str());
}