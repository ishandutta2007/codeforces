import java.io.PrintWriter;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

/**
 * @author Egor Kulikov (kulikov@devexperts.com)
 */
public class RegistrationSystem implements Runnable {
	private Scanner in = new Scanner(System.in);
	private PrintWriter out = new PrintWriter(System.out);

	private Map<String, Integer> s = new HashMap<String, Integer>();
	private String request, ans;

	public static void main(String[] args) {
		new Thread(new RegistrationSystem()).start();
	}

	private void read() {
		request = in.next();
	}

	private void solve() {
		if (!s.containsKey(request)) {
			ans = "OK";
			s.put(request, 0);
		} else {
			s.put(request, s.get(request) + 1);
			ans = request + s.get(request);
		}
	}

	private void write() {
		out.println(ans);
	}

	public void run() {
		int n = in.nextInt();
		for (int i = 0; i < n; i++) {
			read();
			solve();
			write();
		}
		out.close();
	}
}