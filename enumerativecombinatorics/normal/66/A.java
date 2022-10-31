import java.util.*;
import java.math.*;
public class Main{
    public static void main(String args[]){
        Scanner s=new Scanner(System.in);
        BigInteger val=s.nextBigInteger();
        if(val.compareTo(new BigInteger("-128"))!=-1&&val.compareTo(new BigInteger("127"))!=1)System.out.println("byte");
        else if(val.compareTo(new BigInteger("-32768"))!=-1&&val.compareTo(new BigInteger("32767"))!=1)System.out.println("short");
        else if(val.compareTo(new BigInteger("-2147483648"))!=-1&&val.compareTo(new BigInteger("2147483647"))!=1)System.out.println("int");
        else if(val.compareTo(new BigInteger("-9223372036854775808"))!=-1&&val.compareTo(new BigInteger("9223372036854775807"))!=1)System.out.println("long");
        else System.out.println("BigInteger");
    }
}