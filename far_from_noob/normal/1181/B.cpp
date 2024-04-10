#include <iostream>
using namespace std;
#include<bits/stdc++.h>
#define ll long long
#define dd double
#define pb push_back
#define mp make_pair
#define fo(i,n) for(int i=0;i<n;i++)
void sumof(int a[], int l,int la){
    ll lb=l-la;
    int b[lb];
    fo(i,lb)b[i]=a[i+la];
    ll temp=0,c[100005],count=0;
    while(la>0&&lb>0){
        c[count]=(a[la-1]+b[lb-1] + temp)%10;
        //cout<<c[count]<<"fuck";
        temp=(a[la-1]+b[lb-1] + temp)/10;
        la--;
        lb--;
        count++;
    }
    while(la==0 && lb!=0){
        c[count]=(b[lb-1]+ temp)%10;
        temp=(b[lb-1]+temp)/10;
        count++;
        lb--;
        
    }
    while(lb==0 && la!=0){
        c[count]=(a[la-1]+ temp)%10;
        temp=(a[la-1]+temp)/10;
        count++;
        la--;
        
    }
    if(temp==1){c[count]=1;count++;}
    fo(i,count)cout<<c[count-1-i];
}
void compare(int a[], int l,int la,int lc){
    ll lb=l-la;
    //cout<<la<<lb<<"jj";
    int b[lb];
    fo(i,lb)b[i]=a[i+la];
    ll temp=0,c[100005],count=0;
    while(la>0&&lb>0){
        c[count]=(a[la-1]+b[lb-1] + temp)%10;
        //cout<<c[count]<<"fuck";
        temp=(a[la-1]+b[lb-1] + temp)/10;
        la--;
        lb--;
        count++;
    }
    while(la==0 && lb!=0){
        c[count]=(b[lb-1]+ temp)%10;
        temp=(b[lb-1]+temp)/10;
        count++;
        lb--;
        
    }
    while(lb==0 && la!=0){
        c[count]=(a[la-1]+ temp)%10;
        temp=(a[la-1]+temp)/10;
        count++;
        la--;
        
    }if(temp==1){c[count]=1;count++;}
    la=lc;
     lb=l-la;
     b[lb];
    fo(i,lb)b[i]=a[i+la];
    temp=0;
    ll c1[100005],count1=0;
    while(la>0&&lb>0){
        c1[count1]=(a[la-1]+b[lb-1] + temp)%10;
        //cout<<c[count]<<"fuck";
        temp=(a[la-1]+b[lb-1] + temp)/10;
        la--;
        lb--;
        count1++;
    }
    while(la==0 && lb!=0){
        c1[count1]=(b[lb-1]+ temp)%10;
        temp=(b[lb-1]+temp)/10;
        count1++;
        lb--;
        
    }
    while(lb==0 && la!=0){
        c1[count1]=(a[la-1]+ temp)%10;
        temp=(a[la-1]+temp)/10;
        count1++;
        la--;
        
    }
    if(temp==1){c[count]=1;count++;}
    
    int flag=0;
    for(int i=count1-1;i>=0;i--){
        if(flag==0){
            if(c[i]<c1[i]){cout<<c[i];flag=1;}
            else if(c[i]>c1[i]){cout<<c1[i];flag=2;}
            else cout<<c[i];
            
        }
        else if(flag==1)cout<<c[i];
        else cout<<c1[i];
    }
    
}

ll n,k,t,m,q,flag=0,count=0;
int main() {
    cin>>k;
    char c[k];
    int a[k];
    fo(i,k){cin>>c[i];a[i]=c[i]-'0';}
    if(k%2==0){
        if(a[k/2]!=0){
        sumof(a,k,k/2);
        }
        else {
            int i=1;
            while(1){
                if(a[k/2-i]==0 && a[k/2+i]==0){i++;continue;}
                if(a[k/2-i]==0 && a[k/2+i]!=0){
                    sumof(a,k,k/2+i);
                    break;
                }
                if(a[k/2-i]!=0 && a[k/2+i]==0){
                    sumof(a,k,k/2-i);
                    break;
                }
                else {
                    compare(a,k,k/2-i,k/2+i);
                    break;
                }
            }
        }
    }
    else {
        int i=0;
        while(1){
            if(a[k/2-i]==0 && a[k/2+1+i]==0){i++;continue;}
                if(a[k/2-i]==0 && a[k/2+1+i]!=0){
                    sumof(a,k,k/2+i+1);
                    break;
                }
                if(a[k/2-i]!=0 && a[k/2+1+i]==0){
                    sumof(a,k,k/2-i);
                    break;
                }
                else {
                    compare(a,k,k/2-i,k/2+1+i);
                    break;
                }
        }
    }
    
    
    return 0;
}