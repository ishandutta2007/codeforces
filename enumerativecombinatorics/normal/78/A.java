import java.util.*;
public class Main{
    public static void main(String args[]){
        Scanner s=new Scanner(System.in);
        boolean ok=true;
        String line=s.nextLine();
        int count=0;
        for(int i=0;i<line.length();i++)if(line.charAt(i)=='a'||line.charAt(i)=='i'||line.charAt(i)=='u'||line.charAt(i)=='e'||line.charAt(i)=='o')count++;
        if(count!=5)ok=false;
        line=s.nextLine();
        count=0;
        for(int i=0;i<line.length();i++)if(line.charAt(i)=='a'||line.charAt(i)=='i'||line.charAt(i)=='u'||line.charAt(i)=='e'||line.charAt(i)=='o')count++;
        if(count!=7)ok=false;
        line=s.nextLine();
        count=0;
        for(int i=0;i<line.length();i++)if(line.charAt(i)=='a'||line.charAt(i)=='i'||line.charAt(i)=='u'||line.charAt(i)=='e'||line.charAt(i)=='o')count++;
        if(count!=5)ok=false;
        System.out.println(ok?"YES":"NO");
    }
}