#include<stdio.h>  
  
int ans[100005],v[100005];  
  
int main(){  
    long long n,k;  
    scanf("%lld%lld",&n,&k);  
    int i,index=0,cnt=0;//cnt  
    //2  
    while(n){  
        if(n&1){  
            v[index]=1;  
            cnt++;  
        }  
        index++;  
        n/=2;  
    }  
      
    //cntkcnt  
    if(cnt>k){printf("No\n");return 0;}  
    printf("Yes\n");  
      
      
    int minn;  
    //1minnminn  
    for(i=0;i<index;i++){  
        ans[i]=v[index-i-1];  
        if(ans[i])minn=i;  
    }      
  
    //  
    for(i=0;;i++){  
        if(cnt==k)break;  
        if(k-cnt>=ans[i]){  
            cnt+=ans[i];  
            ans[i+1]+=ans[i]*2;  
            ans[i]=0;  
        }  
        else break;  
        if(i+1>minn)minn=i+1;   //  
    }  
      
    //  
    for(;;i++){  
        if(cnt==k)break;  
        cnt++;  
        ans[minn]--;  
        ans[minn+1]+=2;  
        minn++;  
    }  
      
    //  
    int a=index>i?index-1:i;  
    a=minn>a?minn:a;  
      
    //  
    for(i=0;i<=a;i++){  
        while(ans[i]){  
            ans[i]--;  
            minn=index-i-1;  
            printf("%d ",minn);  
        }  
    }  
    printf("\n");  
    return 0;  
}