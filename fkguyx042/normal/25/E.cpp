
 #include<bits/stdc++.h>
#include<cstring>
#define sz 3333333
using namespace std;
int turn[3],b[sz],len[4],mnm,pivot;
char s[4][sz];
bool found1;
    bool f1 =false;

inline void preprocess(int pos){
    int i = 0 , j = -1,l=len[pos];
    b[i]=j;
    while(i<l){
        while(j>=0 &&s[pos][i]!=s[pos][j])j=b[j];
        i++,j++;
        b[i]=j;
    }
}

inline int kmp(int p0,int p1){

    int i = 0 , j = 0, l1 = len[p1],l0=len[p0];

    while(i<l1){
        while(j>=0 && s[p0][j]!=s[p1][i])j=b[j];
        i++,j++;

        if(j==l0){
            found1=true;
            if(i!=l1)j=b[j];
        }
    }
    return j;

}

inline int findPivot(int p0,int p1){

    int l0=len[p0],l1=len[p1],i;

   // if(f1)cout<<"p0:"<<p0<<"\tp1:"<<p1<<"\tl0:"<<l0<<"\tl1:"<<l1<<endl;

    for(i = 0 ; i <l0 && i < l1;i++){
        if(f1){
          //  cout<<"\ti:"<<i<<"\ts[p0][i]:"<<s[p0][i]<<"\ts[p1][i]:"<<s[p1][i]<<endl;
        }
        if(s[p0][i]!=s[p1][i])break;
    }
    return i;

}

inline int concat(int p0,int q){
    int l3=len[3],l0=len[p0];
    for(int i = q;i<l0;i++){
        s[3][l3++]=s[p0][i];
    }
    s[3][l3]='\0';
    return l3;
}

inline void process(){
    mnm=(1<<30);
    for(int i =0 ; i < 3; i++)len[i]=strlen(s[i]);

    turn[0]=0;
    turn[1]=1;
    turn[2]=2;
    do{
        //if(turn[0]==2 && turn[1]==1 && turn[2]==0)f1=true;
      //  cout<<turn[0]<<"\t"<<turn[1]<<"\t"<<turn[2]<<endl;

        s[3][0]='\0';
        len[3]=len[turn[1]];

        strcpy(s[3],s[turn[1]]);
        preprocess(turn[0]);

        //cout<<"s3:"<<s[3]<<endl;

        found1=false;
        pivot=kmp(turn[0],3);
        if(!found1){
            //reverse(s[turn[0]],s[turn[0]]+len[turn[0]]);

            //pivot = findPivot(turn[0],3);

           // reverse(s[turn[0]],s[turn[0]]+len[turn[0]]);

            len[3]=concat(turn[0],pivot);

        }

       // cout<<"s3:"<<s[3]<<endl;
        preprocess(turn[2]);
        pivot=kmp(turn[2],3);

        found1=false;

        if(!found1){



          //  reverse(s[turn[2]],s[turn[2]]+len[turn[2]]);

          //  pivot = findPivot(turn[2],3);

          //  reverse(s[turn[2]],s[turn[2]]+len[turn[2]]);

          //  cout<<"s2:"<<s[turn[2]]<<"\tpivot:"<<pivot<<endl;

            len[3]=concat(turn[2],pivot);

        }

        mnm=min(mnm,len[3]);
       //cout<<"s3:"<<s[3]<<"\tmnm:"<<mnm<<endl;


    }while(next_permutation(turn,turn+3));

    printf("%d\n",mnm);
}


int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
    #endif
    scanf("%s %s %s",s[0],s[1],s[2]);
        process();

    return 0;
}