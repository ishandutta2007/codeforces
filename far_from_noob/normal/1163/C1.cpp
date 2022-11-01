#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >>n;
    int x[n],y[n];
    for(int i=0;i<n;i++){
        cin >>x[i]>>y[i];
    }
    struct line{
        int a;
        int b;
        int c;
    };
    int count=0,t=n*(n-1)/2;
    line l[n*(n-1)/2];
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            l[count].a=y[i]-y[j];
            l[count].b=x[j]-x[i];
            l[count].c=y[i]*(x[j]-x[i]) - x[i]*(y[j]-y[i]);
            count++;
        }
    }
    map<int ,int>ifused;
    int index[t];
    count=0;
    for(int i=0;i<t;i++){
        if(ifused[i]==1)continue;
        ifused[i]=1;
        index[count]=i;
        count++;
        for(int j=i+1;j<t;j++){
            if(l[j].a * l[i].b==l[i].a * l[j].b && l[j].a * l[i].c==l[i].a * l[j].c && l[j].b * l[i].c==l[i].b * l[j].c)
                ifused[j]=1;
        }
    }
    //cout<<count;
    int parallelcount=0;
    for(int i=0;i<count;i++){
        int parallel=0;
        for(int j=i+1;j<count;j++){
            if(l[index[j]].a * l[index[i]].b==l[index[i]].a * l[index[j]].b)
                parallel++;
        }
        parallelcount+=parallel;
        parallel=0;
    }
    cout<< count*(count-1)/2-parallelcount;
    return 0;
}