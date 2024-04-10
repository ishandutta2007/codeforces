//BoyAndGirl
#include <iostream>
#include <string>

using namespace std;

int main(){
    int n=26,start=97, stop=122;
    int count[26];
    int i=0;
    while(i<26){
        count[i]=0;
        i++;
    }
    char letters[n];
    for (int counter=0;start<=stop;start++,counter++){
            letters[counter]=start;
    }
    string username;
    //cout<<"Enter the Username less than 100 characters"<<endl;
    cin>>username;
    int strlength;
    strlength= username.length()-1;
   if (strlength<100){ 
    for(int indexer=0; indexer<=strlength; indexer++){
        if(username[indexer]=='a'){
            count[0]=count[0]+1;    
        } else if(username[indexer]=='b'){
            count[1]=count[1]+1;
        }
        else if(username[indexer]=='c'){
            count[2]=count[2]+1;
        }
        else if(username[indexer]=='d'){
            count[3]=count[3]+1;
        }
        else if(username[indexer]=='e'){
            count[4]=count[4]+1;
        }
        else if(username[indexer]=='f'){
            count[5]=count[5]+1;
        }
        else if(username[indexer]=='g'){
            count[6]=count[6]+1;
        }
        else if(username[indexer]=='h'){
            count[7]=count[7]+1;
        }
        else if(username[indexer]=='i'){
            count[8]=count[8]+1;
        }
        else if(username[indexer]=='j'){
            count[9]=count[9]+1;
        }
        else if(username[indexer]=='k'){
            count[10]=count[10]+1;
        }
        else if(username[indexer]=='l'){
            count[11]=count[11]+1;
        }
        else if(username[indexer]=='m'){
            count[12]=count[12]+1;
        }
        else if(username[indexer]=='n'){
            count[13]=count[13]+1;
        }
        else if(username[indexer]=='o'){
            count[14]=count[14]+1;
        }
        else if(username[indexer]=='p'){
            count[15]=count[15]+1;
        }
        else if(username[indexer]=='q'){
            count[16]=count[16]+1;
        }
        else if(username[indexer]=='r'){
            count[17]=count[17]+1;
        }
        else if(username[indexer]=='s'){
            count[18]=count[18]+1;
        }
        else if(username[indexer]=='t'){
            count[19]=count[19]+1;
        }
        else if(username[indexer]=='u'){
            count[20]=count[20]+1;
        }
        else if(username[indexer]=='v'){
            count[21]=count[21]+1;
        }
        else if(username[indexer]=='w'){
            count[22]=count[22]+1;
        }
        else if(username[indexer]=='x'){
            count[23]=count[23]+1;
        }
        else if(username[indexer]=='y'){
            count[24]=count[24]+1;
        }
        else if(username[indexer]=='z'){
            count[25]=count[25]+1;
        }

    }}
    else {
        cout<<"Greater than 100"<<endl;
    }
    int distinct=0;
    for(int choice=0; choice<26; choice++){
            if(count[choice]>0){
                distinct=distinct+1;
            }
    }
    if (distinct%2==0 && distinct!=0){
        cout<<"CHAT WITH HER!"<<endl;
    }
    else if(distinct%2!=0 && distinct!=0){
        cout<<"IGNORE HIM!"<<endl;
    }
    return 0;
}