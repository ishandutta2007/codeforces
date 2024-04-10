import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintStream;

public class PrA {

	public static long time;

	public static void main(String[] args) throws Exception {
		time = System.currentTimeMillis();
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		go(br, System.out);
		br.close();
		System.exit(0);
	}

	public static void go(BufferedReader br, PrintStream out) throws Exception {
		String[] in = br.readLine().split("WUB");
		String output = in[0];
		for(int i = 1; i < in.length; i++) {
			if(!in[i].equals(""))output = output + " " + in[i];
		}
		output = output.trim();
		out.println(output);
	}

	public static void checkTime() {
		System.out.println(System.currentTimeMillis() - time);
		time = System.currentTimeMillis();
	}
}