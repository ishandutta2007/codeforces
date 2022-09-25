#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
string s,t;
string t2;

int b[500005];

void kmpPreprocess(){
    int i=0,j=-1;
    b[0]=-1;
    while (i<t.size()){
        while (j>=0 && t[i]!=t[j]) j=b[j];
        i++,j++;
        b[i]=j;
    }
}

int o,z;
string fin;

void rage_quit(){
    cout<<fin;
    for (int x=0;x<o;x++) cout<<"0";
    for (int x=0;x<z;x++) cout<<"1";
    exit(0);
}

int main(){
    cin>>s>>t;
    kmpPreprocess();

    int best=0;

    for (int x=1;x<t.size();x++){
        while (best>=0 && t[x]!=t[best]) best=b[best];
        best++;
    }

    t2=t.substr(best,t.size()-best);

    for (int x=0;x<s.size();x++){
        if (s[x]=='0') o++;
        else z++;
    }

    int o1=0,z1=0,o2=0,z2=0;

    for (int x=0;x<t.size();x++){
        if (t[x]=='0') o1++;
        else z1++;
    }
    for (int x=0;x<t2.size();x++){
        if (t2[x]=='0') o2++;
        else z2++;
    }

    if (o1>o || z1>z){
        rage_quit();
    }

    fin+=t;
    o-=o1;
    z-=z1;

    while (o2<=o && z2<=z){
        fin+=t2;
        o-=o2;
        z-=z2;
    }

    rage_quit();
}